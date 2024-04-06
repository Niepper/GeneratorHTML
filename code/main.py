from pathlib import Path

from handlers.cLibrariesHandler import loadLib, libFullPath, ToCArray, ToStructCArray
from handlers.csvHandler import readCSV
if __name__ == '__main__':
    a = readCSV(Path("./code/website/exported/BMI CALC SMALL.csv").absolute())
    for i in a:
        print(i.imie, i.nazwisko, i.plec)
