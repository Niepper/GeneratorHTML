import ctypes
import os
from pathlib import Path

from classes.person import Person

LIB_PATH = "./code/cpp/lib/"
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


def calcBMI(osoby: list[Person]):
    calc = loadLib("example").kalkulator
    for i in osoby:
        calc.argtypes = [ctypes.c_float, ctypes.c_float]
        calc.restype = ctypes.c_float
        i.BMI = round(calc(ctypes.c_float(i.waga), ctypes.c_float(i.wzrost)), 2)
    return osoby
