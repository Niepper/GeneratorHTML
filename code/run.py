import os
import subprocess
import webbrowser
import importlib.util
from pathlib import Path
import venv
import importlib


def run():
    webbrowser.open("http://127.0.0.1:5000")
    subprocess.run(["./venv/bin/python", "./init.py"], capture_output=True, text=True)


def checkVenv():
    if not os.path.exists("./venv"):
        print("Venv not found.")
        venv.create("./venv", with_pip=True)
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
            subprocess.run(["./venv/bin/pip", "install", dependency])


if __name__ == "__main__":
    checkVenv()
    run()
