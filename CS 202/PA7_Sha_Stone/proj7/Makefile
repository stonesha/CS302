TARGET = proj7
HEADERS = MyString.h
CXX = g++ 
CXX_FLAGS = -Wall 

name:proj7.o MyString.o
	g++ proj7.o MyString.o -o proj7

project: proj7.o MyString.o
	g++ proj7.o MyString.o -o proj7

proj7: proj7.cpp MyString.o
	g++ proj7.cpp -o proj7.o

MyString: MyString.cpp MyString.h
	g++ MyString.cpp -o MyString.o

clean:
	-rm -f *.o
	-rm -f $(TARGET)
