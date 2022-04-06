# FileCleaner
A C++ based code cleaner that uses C++ file processing tools to clean code and track changes made. MongoDB integration done with Python (pandas, pymongo) to track change history and provide user with information on cleaning previously done on a file. 
Requires a local MongoDB server running on the default port. Data on cleaning is saved to a local .dat file and can be pushed to MongoDB using the cleanpush executable.
