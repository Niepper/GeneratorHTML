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

    // Add event listeners for the file input
    dropZone.addEventListener('drop', function(e) {
        handleDrop(e, dropZone, fileInput);
    });
    fileInput.addEventListener('change', function() {
        handleFileInput(fileInput, dropZoneText);
    });

    // Add event listener for the upload button
    uploadButton.addEventListener('click', function() {
        window.location.href = '/your-specific-directory';
    });
});

function handleDrop(e, dropZone, fileInput) {
    e.preventDefault();
    dropZone.classList.remove('is-dragover');
    const files = e.dataTransfer.files;
    fileInput.files = files; // Set dropped files to file input
    handleFileInput(fileInput); // Call handleFileInput function to handle dropped files
}

function handleFileInput(fileInput, dropZoneText) {
    const files = fileInput.files;
    if (files.length > 0) {
        dropZoneText.textContent = files[0].name;
        handleFiles(files);
    }
}

function handleFiles(files) {
    const file = files[0];
    if (file && file.name.endsWith('.csv')) {
        uploadFile(file);
    } else {
        alert('Invalid file format. Only CSV files are allowed.');
    }
}

function uploadFile(file) {
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
    .then(result => {
        document.getElementById('upload_button').disabled = false;
    })
    .catch(error => {
        alert('Error uploading file: ' + error.message);
    });
}
