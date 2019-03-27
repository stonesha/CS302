/*
 ============================================================================
 Name        : Stone Sha
 Lab         : 1104
 Date        : 9/1202018
 ============================================================================
 */
#ifndef PROJ4_H_INCLUDED
#define PROJ4_H_INCLUDED

#include <iostream>
#include <fstream>

const int MAX_CHAR = 256;
const int MAX_SENSOR = 3;
const int MAX_CAR = 5;

size_t my_StringLength (const char *str);
int my_StringCompare (const char *str1, const char *str2);
char *my_StringCat (char *dest, const char *src);
char *my_StringCopy (char *dest, const char *src);

void printOptions();

#endif // PROJ4_H_INCLUDED
