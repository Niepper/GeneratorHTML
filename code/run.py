import os
import subprocess
import webbrowser
import importlib.util
from pathlib import Path
import venv

def run():
    webbrowser.open("http://127.0.0.1:5000")
    subprocess.run(["python","./init.py"], capture_output=True, text=True)

def checkVenv():
    if not os.path.exists("./venv"):
        print("Venv not found.")
        venv.create("./venv", with_pip=True)
        subprocess.run(["source", "./venv/bin/activate"])


def checkDependencies():
    with open(Path("./requirements.txt").absolute()) as f:
        a = f.readlines()
    a = map(lambda x: x.split("=")[0], a)
    for dependency in a:
        spec = importlib.util.find_spec(dependency)
        if spec is None:
            subprocess.run(["pip", "install", dependency])
            print(f"Installing {dependency}")

if __name__ == "__main__":
    checkVenv()
    checkDependencies()