from pathlib import Path

from backend.handlers.odinLibrariesHandler import calcBMI, test
from backend.handlers.csvHandler import readCSV

if __name__ == '__main__':
    people = readCSV(Path("./code/frontend/website/exported/BMI CALC SMALL.csv").absolute())

    people = test()
