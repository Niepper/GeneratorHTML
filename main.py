from python.ctypesHandler import loadLib, libFullPath, LIB_PATH
from pathlib import Path

if __name__ == '__main__':
    libname = "example"
    a = libFullPath(libname)
    cFunctions = loadLib(a)
    print(cFunctions.add(5,76))

