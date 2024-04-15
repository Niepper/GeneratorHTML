import csv
from backend.classes.person import Person


def readCSV(file):
    with open(file, newline='') as csvFile:
        CSVReader = csv.reader(csvFile, delimiter=',')
        structArray = []

        csvFile.seek(0)
        next(CSVReader)

        for index, row in enumerate(CSVReader):
            try:
                structArray.append(Person(row[0], row[1], int(row[2]), bool(row[3]), float(row[4]), float(row[5])))
            except ValueError:
                continue

    return structArray
