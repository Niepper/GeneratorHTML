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
    webbrowser.open("http://127.0.0.1:5000")
    subprocess.run([Path("./venv/bin/python").absolute(), "./init.py"], capture_output=True, text=True)


def checkVenv():
    if not os.path.exists(Path("./venv").absolute()):
        print("Venv not found.")
        venv.create(Path("./venv").absolute(), with_pip=True)
        checkDependencies()


def checkDependencies():
    with open(Path("./requirements.txt").absolute()) as f:
        a = f.readlines()
    a = map(lambda x: x.split("=")[0], a)
    for dependency in a:
        try:
            spec = importlib.import_module(dependency)
            print(f"Found {dependency}")
        except ImportError:
            subprocess.run([Path("./venv/bin/pip").absolute(), "install", dependency])


if __name__ == "__main__":
    checkVenv()
    if not shutil.path.exists(Path("./")):
        shutil.mkdir(Path("./frontend/website/templates/reports/"))
        print("Wygenerowano folder")
    run()
