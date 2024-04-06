import csv
from pathlib import Path
from classes.person import Person

# Function that reads csv file and returns dictionary based on the file

def readCSV(file):
    persons = []
    with open(file, newline='') as csv_file:
        CSVReader = csv.reader(csv_file, delimiter=',')
        header = next(CSVReader)  # Skip header row
        for row in CSVReader:
            temp = Person(row[0], row[1], int(row[2]), bool(row[3]), float(row[4]), float(row[5]))
            persons.append(temp)
    return persons

a = readCSV(Path("../website/exported/BMI CALC LARGE.csv").absolute())

print(len(a))