import os
from pathlib import Path

from flask import Flask, render_template, request, redirect, url_for

from backend.handlers.cLibrariesHandler import calcBMI
from backend.handlers.csvHandler import readCSV, sortPeople
from backend.handlers.htmlHandler import generateHTML

app = Flask(__name__)

UPLOAD_FOLDER = Path('./frontend/website/exported').absolute()
REPORT_FOLDER = Path('./frontend/website/templates/reports/').absolute()
if not os.path.exists(UPLOAD_FOLDER):
    os.makedirs(UPLOAD_FOLDER)

app.config['UPLOAD_FOLDER'] = UPLOAD_FOLDER
app.config['REPORT_FOLDER'] = REPORT_FOLDER
currFilePath = ""


@app.route('/')
def index():
    files = list(map(lambda x: x.removesuffix(".html"), os.listdir(app.config['REPORT_FOLDER'])))

    return render_template("index.html", files=files)


@app.route('/upload', methods=['POST'])
def upload():
    global currFilePath
    if 'file' not in request.files:
        return 'No file part'
    file = request.files['file']
    filePath = os.path.join(app.config['UPLOAD_FOLDER'], file.filename)
    if file.filename == '':
        return 'No selected file'

    if file and file.filename.endswith('.csv'):
        file.save(filePath)
        currFilePath = Path(filePath)

        return 'File uploaded successfully'
    else:
        return 'Invalid file format. Only CSV files are allowed.'


@app.route('/reports/<filename>')
def displayReport(filename):
    currFileName = filename
    if ".html" in filename:
        return render_template(f"reports/{filename}", filename=filename, currName=currFileName)
    return render_template(f"reports/{filename}.html", filename=filename, currName=currFileName)


@app.route('/execute', methods=['POST'])
def execute():
    global currFilePath
    if request.method == 'POST':
        people = readCSV(currFilePath.absolute())
        people = calcBMI(people)
        people = sortPeople(people)
        generatedPath = generateHTML(people, currFilePath)

        return redirect(f"/reports/{generatedPath}")
    return 'Something went wrong'


def startWebApp():
    app.run()


if __name__ == '__main__':
    startWebApp()
