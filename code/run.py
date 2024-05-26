import os
import shutil
import subprocess
import webbrowser
import importlib.util
from pathlib import Path
import venv
import importlib

REPORTS_PATH = Path("./frontend/website/templates/reports/").absolute()


def run():
    webbrowser.open("http://127.0.0.1:5331")
    subprocess.run([Path("./venv/Scripts/python").absolute(), "./init.py"], capture_output=True, text=True) if os.name == "nt" else subprocess.run([Path("./venv/bin/python").absolute(), "./init.py"], capture_output=True, text=True)

def checkVenv():
    if not os.path.exists(Path("./venv").absolute()):
        print("Venv not found.")
        venv.create(Path("./venv").absolute(), with_pip=True)
        checkDependencies()
        folderCheck()


def folderCheck():
    try:
        Path("./frontend/website/templates/reports").mkdir(parents=True, exist_ok=True)
    except Exception as e:
        pass




def checkDependencies():
    with open(Path("./requirements.txt").absolute(), encoding="utf-8") as f:
        a = f.readlines()
    a = map(lambda x: x.split("=")[0], a)
    for dependency in a:
        subprocess.run([Path("./venv/bin/pip").absolute(), "install", dependency]) if os.name != "nt" else subprocess.run([Path("./venv/Scripts/pip").absolute(), "install", dependency])


if __name__ == "__main__":
    checkVenv()
    run()
