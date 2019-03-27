/**
 * @brief  CS-202 Project 10 Test Driver
 * @Author Stone Sha (stones@nevada.unr.edu)
 * @date   December, 2018
 *
 * This file is the test driver for Project 11
 */
#include <iostream>
#include <fstream>

#include <vector>

#include "VectorRecursion.h"


int main()
{

    // Vector creation
    std::vector<int> vecInt;

    // Vector population with input values
    std::ifstream fin("RandomData.txt");
    while(fin)
    {
        int fin_in;
        fin >> fin_in;
        if (!fin)
            break;
        vecInt.push_back( fin_in );
    }

    std::vector<int> vecIntCpy = vecInt;

    //quicksort/resort ============================================
    std::cout << "===== TESTING VECTOR_RESORT =====" << std::endl;

    vector_resort(vecInt);
    printVec(vecInt);

    std::cout << "==== VECTOR_RESORT TESTED =====" << std::endl;

    //binary search ==========================================
    std::cout << "===== TESTING VECTOR_RESEARCH =====" << std::endl;
    int index, item = 99;
    index = vector_research(vecInt, item);

    if(index == -1) std::cout << "item: " << item << " was not found." << std::endl;
    else std::cout << "item: " << item << " was found at index: " << index << std::endl;

    item = 8;
    index = vector_research(vecInt, item);
    if(index == -1) std::cout << "item was not found." << std::endl;
    else std::cout << "item: " << item << " was found at index: " << index << std::endl;

    std::cout << "==== VECTOR_RESEARCH TESTED =====" << std::endl;

    return 0;
}
