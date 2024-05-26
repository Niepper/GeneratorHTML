from pathlib import Path

from backend.handlers.cLibrariesHandler import calcBMI, getBMICattegory
from backend.handlers.csvHandler import sortPeople, readCSV
from backend.handlers.htmlHandler import generateHTML
from frontend.website.websiteHandler import website
import waitress


def initialize():
    # waitress.serve(website, host="127.0.0.1", port=5331)
    currFilePath = Path("./frontend/website/TESTDATA/BMI CALC.csv")
    people = readCSV(currFilePath.absolute())
    people = calcBMI(people)
    people = sortPeople(people)
    people = getBMICattegory(people)
    generatedPath = generateHTML(people, currFilePath)


if __name__ == "__main__":
    initialize()
