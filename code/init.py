from frontend.website.websiteHandler import website
import waitress


def initialize():
    waitress.serve(website, host="127.0.0.1", port=5331)

if __name__ == "__main__":
    initialize()
