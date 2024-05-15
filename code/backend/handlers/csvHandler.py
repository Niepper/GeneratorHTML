import csv

from backend.classes.person import Person


def readCSV(file):
    """
    Reads a CSV file and returns a list of Person objects.

    Args:
    file (str): The path to the CSV file.

    Returns:
    list: A list of Person objects, each representing a row in the CSV file.

    Raises:
    ValueError: If any of the values in the CSV file cannot be converted to the appropriate data type.

    Usage:
    person_list = readCSV('path_to_your_file.csv')
    """
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


def sortPeople(arr: list[Person]):
    return sorted(arr, key=lambda x: x.BMI)
