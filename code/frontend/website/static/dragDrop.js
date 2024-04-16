/**
 * Event listener for the 'DOMContentLoaded' event.
 * Initializes the drag-and-drop functionality and event listeners for the file input and upload button.
 * @param {Event} event - The 'DOMContentLoaded' event.
 */
document.addEventListener("DOMContentLoaded", function (event) {
    // Get the DOM elements
    var dropZone = document.getElementById('drop_zone');
    var fileInput = document.getElementById('file_input');
    var uploadButton = document.getElementById('upload_button');
    var dropZoneText = document.getElementById('drop_zone_text');

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
    dropZone.addEventListener('drop', handleDrop);
    fileInput.addEventListener('change', handleFileInput);
    uploadButton.addEventListener('click', handleUploadButtonClick);
});

/**
 * Event listener for the 'drop' event on the drop zone.
 * Prevents the default behavior, removes the 'is-dragover' class, sets the dropped files to the file input,
 * and calls the handleFileInput function to handle the dropped files.
 * @param {Event} e - The 'drop' event.
 */
function handleDrop(e) {
    e.preventDefault();
    dropZone.classList.remove('is-dragover');

    var files = e.dataTransfer.files;
    fileInput.files = files; // Set dropped files to file input
    handleFileInput(); // Call handleFileInput function to handle dropped files
}

/**
 * Event listener for the 'change' event on the file input.
 * Handles the dropped files and checks if the file format is valid (only CSV files are allowed).
 * If the file format is valid, the upload button is enabled; otherwise, it is disabled and an alert is shown.
 * @param {Event} e - The 'change' event.
 */
function handleFileInput() {
    var files = fileInput.files;
    handleFiles(files);
    dropZoneText.textContent = fileInput.files[0].name;
}

/**
 * Function to handle the files and check if the file format is valid.
 * If the file format is valid, the upload button is enabled; otherwise, it is disabled and an alert is shown.
 * @param {FileList} files - The list of selected files.
 */
function handleFiles(files) {
    var file = files[0];
    if (file && file.name.endsWith('.csv')) {
        uploadButton.disabled = false;
    } else {
        uploadButton.disabled = true;
        alert('Invalid file format. Only CSV files are allowed.');
    }
}

/**
 * Event listener for the 'click' event on the upload button.
 * Creates a new FormData object, appends the selected file to it, and sends a POST request to the '/upload' endpoint.
 * If the request is successful, the response text is returned; otherwise, an error alert is shown.
 * @param {Event} e - The 'click' event.
 */
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