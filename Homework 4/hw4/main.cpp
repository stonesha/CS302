/**
 * @file main.cpp
 * @author Stone Sha (stones@nevada.unr.edu)
 * @date March, 2019
 * @brief Test driver for searching through Binary Trees
 */

#include <iostream>
#include <random> //random_device, mt199937, uniform_int_distribution
#include <vector> //std::vector, push_back()
#include <chrono> // std::chrono::system_clock

#include "BinaryNode.h"
#include "BinarySearchTree.h"

void randGen(BinarySearchTree<int> &bst);

int main()
{

    BinarySearchTree<int> test;

    randGen(test);

    std::cout << "===== Height =====" << std::endl
        << test.getHeight() << std::endl;

    test.preorderTraverse();
    test.postorderTraverse();
    test.inorderTraverse();


    return 0;
}


void randGen(BinarySearchTree<int> &bst)
{
    //initialization for random ints
    std::vector<int> randNum;
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    for(int i = 0;i < 200; i++)
        randNum.push_back(i);

    std::shuffle(randNum.begin(), randNum.end(), std::default_random_engine(seed));

    for(int i = 0; i < 100; i++)
    {
        bst.add(randNum[i]);
    }
}
