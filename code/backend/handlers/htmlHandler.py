import os
import re
from pathlib import Path
from lxml import etree, html

from backend.classes.person import Person


def handleNames(PATH):
    FINALNAME = re.sub(r'\.[^.]*$', '', PATH.name)
    FINALNAME = FINALNAME.replace(" ", "_")

    while f"{FINALNAME}.html" in os.listdir("./code/frontend/website/templates/reports/"):
        print("Bazinga")
        FINALNAME += "_Nowy"
    FINALNAME += ".html"
    return FINALNAME


def loadSkeleton():
    with open(Path("./code/backend/skeleton/baseWebsite.html").absolute()) as file:
        f = file.read()
    return f


def fillBoxes(people: list[Person], tree, index=0, id=-1):
    if index < len(tree.xpath("//div[@class='box']")):
        box = tree.xpath("//div[@class='box']")[index]
        if id < len(people):
            box.xpath(".//p")[1].text = f"{people[id].name} {people[id].surname}"
            box.xpath(".//p")[2].text = f"{people[id].BMI}"
    return tree


def fillTable(people: list[Person] = None, tree=None):
    for index, i in enumerate(people):
        table = tree.xpath("//table")[0]
        NewRow = etree.Element("tr")
        cell = etree.SubElement(NewRow, "td")
        cell.text = str(index + 1)
        cell1 = etree.SubElement(NewRow, "td")
        cell1.text = i.name
        cell2 = etree.SubElement(NewRow, "td")
        cell2.text = i.surname
        cell3 = etree.SubElement(NewRow, "td")
        cell3.text = "Kobieta" if i.sex == 1 else "Mężczyzna"
        cell4 = etree.SubElement(NewRow, "td")
        cell4.text = str(i.age)
        cell5 = etree.SubElement(NewRow, "td")
        cell5.text = str(i.weight)
        cell6 = etree.SubElement(NewRow, "td")
        cell6.text = str(i.height)
        cell7 = etree.SubElement(NewRow, "td")
        cell7.text = str(i.BMI)
        cell8 = etree.SubElement(NewRow, "td")
        cell8.text = str(i.desc)
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
    with open(Path(f"./code/frontend/website/templates/reports/{filename}").absolute(), "w") as file:
        file.write(moddified)


if __name__ == '__main__':
    generateHTML()
