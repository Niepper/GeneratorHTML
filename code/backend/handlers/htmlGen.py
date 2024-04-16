from pathlib import Path
# TODO: Use lxml instead

def loadSkeleton():
    with open(Path("../skeleton/baseWebsite.html")) as file:
        f = file.read().splitlines()
    return f


def generateHTML(path = None):
    skeleton = loadSkeleton()
    bodyIndex = skeleton.index("<body>")
    print(skeleton[bodyIndex])


if __name__ == '__main__':
    generateHTML()