import ctypes


class Person(ctypes.Structure):
    _fields_ = [("imie", ctypes.c_char_p),
                ("nazwisko", ctypes.c_char_p),
                ("plec", ctypes.c_bool),
                ("wiek", ctypes.c_int),
                ("waga", ctypes.c_float),
                ("wzrost", ctypes.c_float),
                ("BMI", ctypes.c_float),
                ("opis", ctypes.c_char_p)]

    def __init__(self, imie, nazwisko, plec, wiek, waga, wzrost):
        super().__init__()
        self.imie = ctypes.c_char_p(imie.encode('utf-8'))
        self.nazwisko = ctypes.c_char_p(nazwisko.encode('utf-8'))
        self.plec = ctypes.c_bool(plec)
        self.wiek = ctypes.c_int(wiek)
        self.waga = ctypes.c_float(waga)
        self.wzrost = ctypes.c_float(wzrost)
