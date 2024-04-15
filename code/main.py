from pathlib import Path

from backend.handlers.cLibrariesHandler import calcBMI
from backend.handlers.csvHandler import readCSV

if __name__ == '__main__':
    a = readCSV(Path("./code/frontend/website/exported/BMI CALC SMALL.csv").absolute())

    a = calcBMI(a)
    for i in a:
        print(i.BMI)

