import threading
import time
import webbrowser

import waitress

from frontend.website.websiteHandler import website


def open_browser():
    time.sleep(0.5)
    webbrowser.open("http://127.0.0.1:5331")

def start_server():
    waitress.serve(website, host="127.0.0.1", port=5331)

def initialize():
    browser_thread = threading.Thread(target=open_browser)
    server_thread = threading.Thread(target=start_server)

    browser_thread.start()
    server_thread.start()

    browser_thread.join()
    server_thread.join()

if __name__ == "__main__":
    initialize()
