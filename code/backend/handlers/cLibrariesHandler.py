import ctypes
import os
from pathlib import Path

from backend.classes.person import Person

LIB_PATH = "./backend/cpp/lib/"
LIB_EXTENSION = {"POSIX": ".so", "WIN": ".dll"}
BMI_DESCRIPTION_DICT = {"NW": "Niedowaga", "WP": "Waga prawidłowa", "NaW": "Nadwaga", "OIS": "Otyłość I stopnia",
                        "OIIS": "Otyłość II stopnia"}


# Na podstawie systemu operacyjnego użytkownika wybierana jest prawidłowa dynamiczna biblioteka
def libFullPath(filename: str) -> str:
    if os.name == "nt":
        return str(Path(f"{LIB_PATH}{filename}{LIB_EXTENSION['WIN']}").absolute())
    else:
        return str(Path(f"{LIB_PATH}{filename}{LIB_EXTENSION['POSIX']}").absolute())


def loadLib(filePath: str):
    return ctypes.cdll.LoadLibrary(libFullPath(filePath))


def calcBMI(osoby: list[Person]) -> list[Person]:
    """
    Calculates the Body Mass Index (BMI) for a list of Person objects.

    Args:
    osoby (list[Person]): A list of Person objects with weight and height attributes.

    Returns:
    list[Person]: A list of Person objects with the BMI attribute calculated.

    Raises:
    Exception: If the "BMICalc" library is not found or the "kalkulator" function is not available.

    ```
    """
    calc = loadLib("BMICalc").kalkulator
    for i in osoby:
        calc.argtypes = [ctypes.c_float, ctypes.c_float]
        calc.restype = ctypes.c_float
        i.BMI = round(calc(ctypes.c_float(i.weight), ctypes.c_float(i.height)), 2)
    return osoby


def getBMICattegory(osoby: list[Person]) -> list[Person]:
    BMICat = loadLib("BMICalc").getBMICategory
    for i in osoby:
        BMICat.argtypes = [ctypes.c_float, ctypes.c_bool, ctypes.c_int]
        BMICat.restype = ctypes.c_char_p
        temp = BMICat(ctypes.c_float(i.BMI), ctypes.c_bool(i.sex), ctypes.c_int(i.age)).decode()
        i.desc = BMI_DESCRIPTION_DICT[temp]
    return osoby
