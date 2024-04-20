import ctypes
import os
from pathlib import Path

from backend.classes.person import Person

LIB_PATH = "./code/backend/odin/lib/"
LIB_EXTENSION = {"POSIX": ".so", "WIN": ".dll"}


# Na podstawie systemu operacyjnego użytkownika wybierana jest prawidłowa dynamiczna biblioteka
def libFullPath(filename: str) -> str:
    if os.name == "nt":
        return str(Path(f"{LIB_PATH}{filename}{LIB_EXTENSION['WIN']}").absolute())
    else:
        return str(Path(f"{LIB_PATH}{filename}{LIB_EXTENSION['POSIX']}").absolute())


def loadLib(filePath: str):
    return ctypes.cdll.LoadLibrary(libFullPath(filePath))


# Zmiana listy na typ kompatybilny z c++
def ToCArray(pyList: list, itemType=ctypes.c_int):
    return (itemType * len(pyList))(*list(map(lambda x: ctypes.c_int(int(x)), pyList)))


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
    calc = loadLib("calculate").calcBmi
    for i in osoby:
        calc.argtypes = [ctypes.c_float, ctypes.c_float]
        calc.restype = ctypes.c_float
        i.BMI = round(calc(ctypes.c_float(i.weight), ctypes.c_float(i.height)), 2)
    return osoby


def test():
    test = loadLib("calculate").describeBMI
    test.argtypes = [ctypes.c_int, ctypes.c_bool, ctypes.c_float, ctypes.c_char_p]
    test.restypes = ctypes.c_char_p
    a = b""
    b = test(24,1,24.4,a)
    print(b)
    print(a)
