from handlers.cLibrariesHandler import loadLib, libFullPath, cArray

if __name__ == '__main__':
    # Zdobycie ścieżki do biblioteki
    libPath = libFullPath("example")

    cFunctions = loadLib(libPath)

    print(cFunctions.add(2, 2))

    a = [3, 6, 7, 9]
    b = [2, 6, 2, 4]

    a_c = cArray(a)
    b_c = cArray(b)

    cFunctions.subtractArrays(a_c, b_c, len(a))

    print(list(a_c))
