import os
from pathlib import Path

from flask import Flask, render_template, request

app = Flask(__name__)

UPLOAD_FOLDER = './code/frontend/website/exported'
REPORT_FOLDER = './code/frontend/website/templates/reports/'
if not os.path.exists(UPLOAD_FOLDER):
    os.makedirs(UPLOAD_FOLDER)

app.config['UPLOAD_FOLDER'] = UPLOAD_FOLDER


@app.route('/')
def index():
    files = list(map(lambda x: x.removesuffix(".html"), os.listdir(REPORT_FOLDER)))

    return render_template("index.html", files=files)


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


@app.route('/reports/<filename>')
def report(filename):
    currFileName = filename
    if ".html" in filename:
        return render_template(f"reports/{filename}", filename=filename, currName=currFileName)
    return render_template(f"reports/{filename}.html", filename=filename, currName=currFileName)


def startWebApp():
    app.run()


if __name__ == '__main__':
    startWebApp()
