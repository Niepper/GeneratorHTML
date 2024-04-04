import ctypes
import os
from pathlib import Path

LIB_PATH = "./code/cpp/lib/"
LIB_EXTENSION = {"POSIX": ".so", "WIN": ".dll"}


def libFullPath(filename: str):
    if os.name == "nt":
        return Path(f"{LIB_PATH}{filename}{LIB_EXTENSION['WIN']}").absolute()
    else:
        return Path(f"{LIB_PATH}{filename}{LIB_EXTENSION['POSIX']}").absolute()


def loadLib(filePath: Path):
    return ctypes.cdll.LoadLibrary(str(filePath))


# noinspection PyCallingNonCallable
def cArray(a: list):
    return (ctypes.c_int * len(a))(*a)
