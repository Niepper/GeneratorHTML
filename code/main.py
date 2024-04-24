from pathlib import Path

from backend.handlers.cLibrariesHandler import calcBMI
from backend.handlers.csvHandler import readCSV, sortPeople

if __name__ == '__main__':
    people = readCSV(Path("./code/frontend/website/exported/BMI CALC.csv").absolute())

    people = calcBMI(people)
    people = sortPeople(people)
