import ctypes
from pathlib import Path

from classes.person import Person
from handlers.cLibrariesHandler import loadLib, libFullPath, ToCArray, calcBMI
from website.flaskBackend import startWebApp
from handlers.csvHandler import readCSV

if __name__ == '__main__':
    a = readCSV(Path("./code/website/exported/BMI CALC SMALL.csv").absolute())

    a = calcBMI(a)
    for i in a:
        print(i.BMI)

