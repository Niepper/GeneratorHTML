class Person:

    def __init__(self, name, surname, sex, age, weight, height):
        self.name = name
        self.surname = surname
        self.sex = bool(sex)
        self.age = int(age)
        self.weight = float(weight)
        self.height = float(height)
        self.BMI = 0
        self.desc = "None"
