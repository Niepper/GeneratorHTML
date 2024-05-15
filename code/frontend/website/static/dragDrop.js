document.addEventListener("DOMContentLoaded", function () {
    // Get the DOM elements
    const dropZone = document.getElementById('drop_zone');
    const fileInput = document.getElementById('file_input');
    const uploadButton = document.getElementById('upload_button');
    const dropZoneText = document.getElementById('drop_zone_text');

    // Add event listener for clicking on the drop zone
    dropZone.addEventListener('click', function () {
        fileInput.click();
    });

    // Add event listeners for drag-and-drop events
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

    // Add event listeners for the file input and upload button
    dropZone.addEventListener('drop', function(e) {
        handleDrop(e, dropZone, fileInput);
    });
    fileInput.addEventListener('change', function() {
        handleFileInput(fileInput, dropZoneText, uploadButton);
    });
    uploadButton.addEventListener('click', function() {
        handleUploadButtonClick(fileInput);
    });
});

function handleDrop(e, dropZone, fileInput) {
    e.preventDefault();
    dropZone.classList.remove('is-dragover');
    const files = e.dataTransfer.files;
    fileInput.files = files; // Set dropped files to file input
    handleFileInput(fileInput); // Call handleFileInput function to handle dropped files
}

function handleFileInput(fileInput, dropZoneText, uploadButton) {
    const files = fileInput.files;
    handleFiles(files, uploadButton);
    if (files.length > 0) {
        dropZoneText.textContent = files[0].name;
    }
}

function handleFiles(files, uploadButton) {
    const file = files[0];
    if (file && file.name.endsWith('.csv')) {
        uploadButton.disabled = false;
    } else {
        uploadButton.disabled = true;
        alert('Invalid file format. Only CSV files are allowed.');
    }
}

function handleUploadButtonClick(fileInput) {
    const file = fileInput.files[0];
    const formData = new FormData();
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
