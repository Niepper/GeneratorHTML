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
        venv.create("./", with_pip=True)


def checkDependencies():
    with open(Path("./requirements.txt").absolute()) as f:
        a = f.readlines()
    a = map(lambda x: x.split("=")[0], a)
    for dependency in a:
        spec = importlib.util.find_spec(dependency)
        print(f"{spec} {dependency}")

if __name__ == "__main__":
    checkVenv()