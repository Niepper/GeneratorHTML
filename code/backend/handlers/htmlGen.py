from pathlib import Path
from lxml import etree

def loadSkeleton():
    return etree.parse(Path("../skeleton/baseWebsite.html"))


def generateHTML(path = None):
    skeleton = loadSkeleton()
    bodyIndex = skeleton.index("<body>")
    print(skeleton[bodyIndex])


if __name__ == '__main__':
    generateHTML()