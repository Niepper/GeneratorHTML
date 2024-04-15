import ctypes
from pathlib import Path

from classes.person import Person
from handlers.cLibrariesHandler import loadLib, libFullPath, ToCArray
from website.flaskBackend import startWebApp
from handlers.csvHandler import readCSV

if __name__ == '__main__':
    a = readCSV(Path("./code/website/exported/BMI CALC SMALL.csv").absolute())

    b = loadLib("example").kalkulator

    map(b,)