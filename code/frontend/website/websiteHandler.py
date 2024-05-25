import os
from pathlib import Path

from flask import Flask, render_template, request, redirect

from backend.handlers.cLibrariesHandler import calcBMI, getBMICattegory
from backend.handlers.csvHandler import readCSV, sortPeople
from backend.handlers.htmlHandler import generateHTML

UPLOAD_FOLDER = Path('./frontend/website/exported').absolute()
REPORT_FOLDER = Path('./frontend/website/templates/reports/').absolute()

if not os.path.exists(UPLOAD_FOLDER):
    os.makedirs(UPLOAD_FOLDER)

website = Flask(__name__)
website.config['UPLOAD_FOLDER'] = UPLOAD_FOLDER
website.config['REPORT_FOLDER'] = REPORT_FOLDER
currFilePath = ""


@website.route('/')
def index():
    files = list(map(lambda x: x.removesuffix(".html"), os.listdir(website.config['REPORT_FOLDER'])))
    return render_template("index.html", files=files)


@website.route('/upload', methods=['POST'])
def upload():
    global currFilePath
    if 'file' not in request.files:
        return 'No file part'
    file = request.files['file']
    filePath = os.path.join(website.config['UPLOAD_FOLDER'], file.filename)
    if file.filename == '':
        return 'No selected file'

    if file and file.filename.endswith('.csv'):
        file.save(filePath)
        currFilePath = Path(filePath)
        return 'File uploaded successfully'
    else:
        return 'Invalid file format. Only CSV files are allowed.'


@website.route('/reports/<filename>')
def displayReport(filename):
    currFileName = filename
    if ".html" in filename:
        return render_template(f"reports/{filename}", filename=filename, currName=currFileName)
    return render_template(f"reports/{filename}.html", filename=filename, currName=currFileName)


@website.route('/execute', methods=['POST'])
def execute():
    global currFilePath
    if request.method == 'POST':
        people = readCSV(currFilePath.absolute())
        people = calcBMI(people)
        people = sortPeople(people)
        people = getBMICattegory(people)
        generatedPath = generateHTML(people, currFilePath)
        return redirect(f"/reports/{generatedPath}")
    return 'Something went wrong'

if __name__ == '__main__':
    website.run(debug=True)