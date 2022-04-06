import pandas as pd
from pymongo import MongoClient
import pymongo
import sys
import os

DATA_FILE_PATH = "C:\\Projects\\cleaner\\data.dat"

if __name__ == "__main__":

    try:
        df = pd.read_csv(DATA_FILE_PATH, header=None)
    except:
        print("No new files were cleaned since the last insertion.")
        open(DATA_FILE_PATH, "w").close()
        sys.exit()
    myclient = pymongo.MongoClient("mongodb://localhost:27017/")
    mydb = myclient["cleanerdata"]
    mycol = mydb["cleaned"]

    # Check if MongoDB local server is running
    try:
        dblist = myclient.list_database_names()
    except:
        print("The MongoDB server is not running.")
        sys.exit()
    
    # Iterate through data file and make MongoDB insertions from dict
    for index, row in df.iterrows():
        inserted = {"path": row[0], "spaces": row[1], "newlines": row[2], "ifndefs": row[3], "defines": row[4]}
        obj = mycol.insert_one(inserted)
    
    print("The insertion was successful.")
    if os.path.exists(DATA_FILE_PATH):
        open(DATA_FILE_PATH, "w").close()