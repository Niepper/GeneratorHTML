import os
from pathlib import Path
import datetime

from backend.handlers.cLibrariesHandler import calcBMI
from backend.handlers.csvHandler import readCSV, sortPeople
from backend.handlers.htmlHandler import generateHTML
import re



if __name__ == '__main__':
    PATH = Path("./code/frontend/website/exported/BMI CALC SMALL.csv")


    people = readCSV(PATH.absolute())

    people = calcBMI(people)
    people = sortPeople(people)
    generateHTML(people, PATH)