from pathlib import Path
from lxml import etree, html

from backend.classes.person import Person


# TODO: Use lxml instead

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
    pass


def generateHTML(people: list[Person] = None):
    skeleton = loadSkeleton()
    tree = html.fromstring(skeleton)

    tree = fillBoxes(people, tree)
    tree = fillBoxes(people, tree, 1, 0)

    moddified = html.tostring(tree, encoding="unicode")
    with open(Path("./test.html").absolute(), "w") as file:
        print(Path("./test.html").absolute())
        file.write(moddified)


if __name__ == '__main__':
    generateHTML()
