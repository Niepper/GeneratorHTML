import os
from pathlib import Path
import datetime

from backend.handlers.cLibrariesHandler import calcBMI
from backend.handlers.csvHandler import readCSV, sortPeople
from backend.handlers.htmlHandler import generateHTML
import re

from frontend.website.websiteHandler import startWebApp

if __name__ == '__main__':
    startWebApp()
