class Person():

    def __init__(self, imie, nazwisko, plec, wiek, waga, wzrost):
        self.imie = imie
        self.nazwisko = nazwisko
        self.plec = bool(plec)
        self.wiek = int(wiek)
        self.waga = float(waga)
        self.wzrost = float(wzrost)
        self.BMI = 0
        self.opis = "None"
