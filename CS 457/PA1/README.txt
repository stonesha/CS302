The program doesn't support a filename-argument interface, you have to run the program and type 
each command one at a time. Multiple databases are handled by creating directories for them. Multiple
tables are handled byt pushing them into a vector of table classes.

Compile using:
	 g++ -std=c++11 main.cpp -o main