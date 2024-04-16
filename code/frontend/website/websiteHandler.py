import os
from pathlib import Path

from flask import Flask, render_template, request

app = Flask(__name__)

UPLOAD_FOLDER = './code/frontend/website/exported'
if not os.path.exists(UPLOAD_FOLDER):
    os.makedirs(UPLOAD_FOLDER)

app.config['UPLOAD_FOLDER'] = UPLOAD_FOLDER


@app.route('/')
def index():
    return render_template("index.html")


@app.route('/upload', methods=['POST'])
def upload():
    if 'file' not in request.files:
        return 'No file part'
    file = request.files['file']
    filePath = os.path.join(app.config['UPLOAD_FOLDER'], file.filename)
    if file.filename == '':
        return 'No selected file'

    if file and file.filename.endswith('.csv'):
        file.save(filePath)
        return 'File uploaded successfully'
    else:
        return 'Invalid file format. Only CSV files are allowed.'





def startWebApp():
    app.run()


if __name__ == '__main__':
    startWebApp()
