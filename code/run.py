import itertools
import os
import subprocess
import sys
import threading
import time
import webbrowser
from pathlib import Path
from plyer import notification

import venv

REPORTS_PATH = Path("./frontend/website/templates/reports/").absolute()


def run():
    webbrowser.open("http://127.0.0.1:5331")
    subprocess.run([Path("./venv/Scripts/python").absolute(), "./init.py"], capture_output=True, text=True) if os.name == "nt" else subprocess.run([Path("./venv/bin/python").absolute(), "./init.py"], capture_output=True, text=True)

def checkVenv():
    if not os.path.exists(Path("./venv").absolute()):
        if not isTerm():
            notification.notify(
                title="Generator HTML",
                message="Pobieranie zależności. Proszę czekać.",
                app_name="GeneratorHTML",
                timeout=30
            )
        print("Venv not found.\nPlease Wait...")
        venv.create(Path("./venv").absolute(), with_pip=True)
        checkDependencies()
        folderCheck()

def loading(stop_event):
    for char in itertools.cycle('⣾⣽⣻⢿⡿⣟⣯⣷'):
        if stop_event.is_set():
            break
        sys.stdout.write(f'\rLoading... {char}')
        sys.stdout.flush()
        time.sleep(0.1)
    sys.stdout.write('\rFinished     \n')


def folderCheck():
    try:
        Path("./frontend/website/templates/reports").mkdir(parents=True, exist_ok=True)
    except Exception as e:
        pass

def isTerm():
    if os.isatty(sys.stdin.fileno()):
        return True
    return False

def checkDependencies():
    with open(Path("./requirements.txt").absolute(), encoding="utf-8") as f:
        a = f.readlines()
    a = map(lambda x: x.split("=")[0], a)
    for dependency in a:
        subprocess.run([Path("./venv/bin/pip").absolute(), "install", dependency]) if os.name != "nt" else subprocess.run([Path("./venv/Scripts/pip").absolute(), "install", dependency])


if __name__ == "__main__":

    stop = threading.Event()
    animation = threading.Thread(target=loading, args=(stop,))
    animation.start()
    checkVenv()
    stop.set()
    animation.join()
    if not isTerm():
        notification.notify(
            title="Generator HTML",
            message="Uruchamianie WebUI",
            app_name="GeneratorHTML",
            timeout=10
        )
    run()