import os
from ctypes import cdll
from pathlib import Path


def loadLib(filePath: Path):
    return cdll.LoadLibrary(str(filePath))



LIB_PATH = "./cpp/lib/"
LIB_EXTENSION = {"POSIX":".so", "WIN":".dll"}


def libFullPath(filename: str):
    if os.name == "nt":
        return Path(f"{LIB_PATH}{filename}{LIB_EXTENSION["WIN"]}").absolute()
    else:
        return Path(f"{LIB_PATH}{filename}{LIB_EXTENSION["POSIX"]}").absolute()
