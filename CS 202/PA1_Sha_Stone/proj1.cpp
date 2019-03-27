/*
 ============================================================================
 Name        : Stone Sha
 Lab         : 1104
 Date        : 9/3/2018
 ============================================================================
 */
#include <iostream>
#include <fstream>

#define MAX 9 //maximum length of names including the null character
#define FIXED 10 // exactly 10 entries of names

using namespace std;

//Function prototype
void myStringCopy(char destination[], const char souce[]);
int myStringLength(const char str[]);
int myStringCompare(const char str1[], const char str2[]);
void sortLength(char nam[FIXED][MAX], int ord[]);
void sortAlpha(char nam[FIXED][MAX], int ord[MAX]);
void printWrite(char nam[FIXED][MAX], int ord[MAX], ofstream& outF);

int main(){

    //initialization
    ifstream inFile;
    ofstream lengthFile, alphaFile;
    char names[FIXED][MAX], input[20], outputL[20], outputA[20];
    int i = 0, j = 0, strlen, order[FIXED] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    //input and output for file names
    cout << "Enter input file name: ";
    cin >> input;

    cout << "Enter output file name for length: ";
    cin >> outputL;

    cout << "Enter output file name for alphabetization: ";
    cin >> outputA;

    //opening files
    inFile.open(input);
    lengthFile.open(outputL);
    alphaFile.open(outputA);

    cout << "Unsorted Data (Original Input Order and Name)" << endl << "=============================" << endl;

    //Unsorted
    for(i = 0; i < FIXED; i++){
        cout << order[i] << " ";
        inFile >> names[i];
        cout << names[i] << endl;
    }

    cout << endl;

    //Length Sort Print and Write to File
    cout << "Sorted-by-Length Data (Original Input Order and Name)" << endl << "===========================" << endl;
    sortLength(names, order);
    lengthFile << "Sorted-by-Length Data (Original Input Order and Name)" << endl << "===========================" << endl;
    printWrite(names, order, lengthFile);

    //Alphabetical Sort Print and Write to File
    cout << "Alphabetically Sorted Data (Original Input Order and Name)" << endl << "===========================" << endl;
    sortAlpha(names, order);
    alphaFile << "Alphabetically Sorted Data (Original Input Order and Name)" << endl << "===========================" << endl;
    printWrite(names, order, alphaFile);

    inFile.close();
    lengthFile.close();
    alphaFile.close();

    return 0;
}


//Print to cout and write to file --------------------------------------------------------------
void printWrite(char nam[FIXED][MAX], int ord[MAX], ofstream& outF){

    for(int i = 0; i < FIXED; i++){

        cout << ord[i] << " ";
        cout << nam[i] << endl;
        outF << ord[i] << " ";
        outF << nam[i] << endl;

    }

    cout << endl;
    outF << endl;

}


//Used to sort the char array by length --------------------------------------------------------------
void sortLength(char nam[FIXED][MAX], int ord[MAX]){

    int i;

    //Bubble Sort
    for(i = 0;i < FIXED - 1; i++){

        for(int j = 0;j < FIXED - 1; j++){

            if(myStringLength(nam[j]) > myStringLength(nam[j + 1])) {

                swap(nam[j + 1], nam[j]);
                swap(ord[j + 1], ord[j]);

            }
        }
    }

}


//used to sort array by alphabetical ----------------------------------------------------
void sortAlpha(char nam[FIXED][MAX], int ord[MAX]){

    int i;

    //Bubble Sort
    for(i = 0;i < FIXED - 1; i++){

        for(int j = 0;j < FIXED - 1; j++){

            if(myStringCompare(nam[j], nam[j + 1]) == 1){

                swap(nam[j + 1], nam[j]);
                swap(ord[j + 1], ord[j]);

            }
        }
    }

}


//Used to copy Strings------------------------------------------------------------------------
void myStringCopy(char destination[], const char source[]){

    int i = 0;

    for(i = 0; source[i] != '\0'; ++i){

        destination[i] = source[i];

    }

     destination[i] = '\0';

}//suck my weewee


//Used to Determine String Length-----------------------------------------------------------------
int myStringLength(const char str[]){

    int i = 0, len = 0;

    for(i = 0; str[i] != '\0'; i++){

        len++;

    }

    return len;
}


//Used to compare Strings-----------------------------------------------------------------
int myStringCompare(const char str1[], const char str2[]){

    int i = 0;

    for(i = 0; str1[i] == str2[i] ; i++){
        if(str1[i] && str2[i] == '\0'){ return 0;}
    }

    return str1[i] > str2[i] ? 1 : -1;

}
