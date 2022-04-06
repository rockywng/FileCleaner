from pymongo import MongoClient
import pymongo
import sys

if __name__ == "__main__":
    #print(len(sys.argv))
    if (len(sys.argv) != 2):
        print("Please ensure the only argument is the path to a file that was cleaned.")
        sys.exit()
    # Get path to file from command line args
    path = str(sys.argv[1])
    myclient = pymongo.MongoClient("mongodb://localhost:27017/")
    mydb = myclient["cleanerdata"]
    mycol = mydb["cleaned"]

    # Check if MongoDB local server is running
    try:
        dblist = myclient.list_database_names()
    except:
        print("The MongoDB server is not running.")
        sys.exit()
    # Get all entries based on provided path
    y = mycol.find({"path": path}).limit(1).sort([('$natural',-1)])
    entries = list(y)
    #print("found")
    if (len(entries) == 0):
        print("Data on this file could not be found.")
    else:
        spaces = entries[0]['spaces']
        newlines = entries[0]['newlines']
        ifndefs = entries[0]['ifndefs']
        defines = entries[0]['defines']
        print("Here are the changes that were made the last time you cleaned this file.")
        print("Spaces Added: " + str(spaces))
        print("Newlines Added: " + str(newlines))
        if (path[len(path) - 2:] == ".h"):
            print("Ifndef Include Guards Added: " + str(ifndefs))
            print("Define Include Guards Added: " + str(defines))