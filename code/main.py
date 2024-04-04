from python.cLibrariesHandler import loadLib, libFullPath

if __name__ == '__main__':

    libPath = libFullPath("example")
    cFunctions = loadLib(libPath)

    print(cFunctions.add(2, 2))
    print(cFunctions.substract(10, 2))

