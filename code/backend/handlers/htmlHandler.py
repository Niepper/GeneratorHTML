import os
import re
from pathlib import Path
from lxml import etree, html

from backend.classes.person import Person


def handleNames(PATH):
    FINALNAME = re.sub(r'\.[^.]*$', '', PATH.name)
    FINALNAME = FINALNAME.replace(" ", "_")

    while f"{FINALNAME}.html" in os.listdir("./frontend/website/templates/report/"):
        print("Bazinga")
        FINALNAME += "_Nowy"
    FINALNAME += ".html"
    return FINALNAME


def loadSkeleton():
    with open(Path("./backend/skeleton/baseWebsite.html").absolute()) as file:
        f = file.read()
    return f


def fillBoxes(people: list[Person], tree, index=0, id=-1):
    if index < len(tree.xpath("//div[@class='box']")):
        box = tree.xpath("//div[@class='box']")[index]
        if id < len(people):
            box.xpath(".//p")[1].text = f"{people[id].name} {people[id].surname}"
            box.xpath(".//p")[2].text = f"{people[id].BMI}"
    return tree


def generateCell(tree, value, row):

    cell = etree.SubElement(row, "td")
    cell.text = str(value)

    return tree


def fillTable(people: list[Person] = None, tree=None):
    for index, i in enumerate(people):
        table = tree.xpath("//table")[0]
        NewRow = etree.Element("tr")
        generateCell(tree, index + 1, NewRow)
        generateCell(tree, i.name, NewRow)
        generateCell(tree, i.surname, NewRow)
        generateCell(tree, "Kobieta" if i.sex == 1 else "Mężczyzna", NewRow)
        generateCell(tree, i.age, NewRow)
        generateCell(tree, i.weight, NewRow)
        generateCell(tree, i.height, NewRow)
        generateCell(tree, i.BMI, NewRow)
        generateCell(tree, i.desc, NewRow)

        NewRow.set("class", "item")
        table.append(NewRow)
    return tree


def generateHTML(people: list[Person] = None, path=None):
    filename = handleNames(Path(path))

    skeleton = loadSkeleton()
    tree = html.fromstring(skeleton)

    tree = fillBoxes(people, tree)
    tree = fillBoxes(people, tree, 1, 0)

    tree = fillTable(people, tree)

    moddified = html.tostring(tree, encoding="unicode")
    with open(Path(f"./frontend/website/templates/report/{filename}").absolute(), "w") as file:
        file.write(moddified)
    return filename


if __name__ == '__main__':
    generateHTML()
