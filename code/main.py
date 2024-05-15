from pathlib import Path

from backend.handlers.cLibrariesHandler import calcBMI
from backend.handlers.csvHandler import readCSV, sortPeople
from backend.handlers.htmlGen import generateHTML

if __name__ == '__main__':
    people = readCSV(Path("./code/frontend/website/exported/BMI CALC.csv").absolute())

    people = calcBMI(people)
    people = sortPeople(people)
    generateHTML(people)