import ctypes
from pathlib import Path

from classes.person import Person
from handlers.cLibrariesHandler import loadLib, libFullPath, ToCArray
from website.flaskBackend import startWebApp
from handlers.csvHandler import readCSV

if __name__ == '__main__':
    a = readCSV(Path("./code/website/exported/BMI CALC SMALL.csv").absolute())

    b = loadLib("example").kalkulator

    for i in a:
        b.argtypes = [ctypes.c_float, ctypes.c_float]
        b.restype = ctypes.c_float
        i.BMI = round(b(ctypes.c_float(i.waga), ctypes.c_float(i.wzrost)),2)
        print(i.BMI)