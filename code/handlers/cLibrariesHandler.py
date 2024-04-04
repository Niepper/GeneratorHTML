import ctypes
import os
from pathlib import Path

LIB_PATH = "./code/cpp/lib/"
LIB_EXTENSION = {"POSIX": ".so", "WIN": ".dll"}


# Na podstawie systemu operacyjnego użytkownika wybierana jest prawidłowa dynamiczna biblioteka


def libFullPath(filename: str):
    if os.name == "nt":
        return Path(f"{LIB_PATH}{filename}{LIB_EXTENSION['WIN']}").absolute()
    else:
        return Path(f"{LIB_PATH}{filename}{LIB_EXTENSION['POSIX']}").absolute()


def loadLib(filePath: Path):
    return ctypes.cdll.LoadLibrary(str(filePath))


# Zmiana listy na typ kompatybilny z c++
def cArray(pyList: list, itemType=ctypes.c_int):
    return (itemType * len(pyList))(*[ctypes.c_int(int(i)) for i in pyList])
