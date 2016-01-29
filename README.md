#Processeing Issued Checks
Final project for the intro to algorithms and data structures class. 

# About
This application allows a user to manage the proccessing of issued checks.
It is in truth a big simplification of the real process.

The application consists of two entities - Client and Check. 
When a check is issued two Clients are associated with it and it is given a reference. The check is then added to the pool of checks to be processed.

The app allows the following commands:
* issue a check
* process a specific check by reference
* process the check that has been in the pool the longest
* get info about a specific check
* get info about a specific client
* get a list of info about all the clients by order of reference

For the fast execution of these commands, we use an AVL (balanced binary tree) to store the Clients and a Queue (FIFO) for the Checks.

# Using
You should clone the repo and compile all the files. 

The main function is found in the *INTERFACE.c* file.

Then run the executable.
