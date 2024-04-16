document.addEventListener("DOMContentLoaded", function () {
    var dropZone = document.getElementById('drop_zone');
    var fileInput = document.getElementById('file_input');
    var uploadButton = document.getElementById('upload_button');
    var dropZoneText = document.getElementById('drop_zone_text');

    dropZone.addEventListener('click', function () {
        fileInput.click();
    });

    ['dragover', 'dragenter'].forEach(eventName => {
        dropZone.addEventListener(eventName, function(e) {
            e.preventDefault();
            dropZone.classList.add('is-dragover');
        });
    });

    ['dragleave', 'dragend', 'drop'].forEach(eventName => {
        dropZone.addEventListener(eventName, function() {
            dropZone.classList.remove('is-dragover');
        });
    });

    dropZone.addEventListener('drop', handleDrop);
    fileInput.addEventListener('change', handleFileInput);
    uploadButton.addEventListener('click', handleUploadButtonClick);

    function handleDrop(e) {
    e.preventDefault();
    dropZone.classList.remove('is-dragover');

    var files = e.dataTransfer.files;
    fileInput.files = files; // Set dropped files to file input
    handleFileInput(); // Call handleFileInput function to handle dropped files
}


    function handleFileInput() {
        var files = fileInput.files;
        handleFiles(files);
        dropZoneText.textContent = fileInput.files[0].name;
    }

    function handleFiles(files) {
        var file = files[0];
        if (file && file.name.endsWith('.csv')) {
            uploadButton.disabled = false;
        } else {
            uploadButton.disabled = true;
            alert('Invalid file format. Only CSV files are allowed.');
        }
    }

    function handleUploadButtonClick() {
        var file = fileInput.files[0];
        var formData = new FormData();
        formData.append('file', file);

        fetch('/upload', {
            method: 'POST',
            body: formData
        })
        .then(response => {
            if (response.ok) {
                return response.text();
            } else {
                throw new Error('Error uploading file: ' + response.statusText);
            }
        })
        .catch(error => {
            alert('Error uploading file: ' + error.message);
        });
    }
});
