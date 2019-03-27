/**
 * @file main.cpp
 * @author Stone Sha (stones@nevada.unr.edu)
 * @date March, 2019
 * @brief Test driver for searching through Binary Trees
 */

#include <iostream>
#include <random> //random_device, mt199937, uniform_int_distribution
#include <vector> //std::vector, push_back(), begin(), end()
#include <chrono> // std::chrono::system_clock
#include <algorithm> //std::shuffle

#include "BinaryNode.h"
#include "BinarySearchTree.h"

void randGen(BinarySearchTree<int> &bst);

int main()
{

    //bst initialized
    BinarySearchTree<int> test;

    //randomly filled values
    randGen(test);

    //prints height
    std::cout << "===== Height =====" << std::endl
        << test.getHeight() << std::endl;

    //different types of traversals
    test.preorderTraverse();
    test.postorderTraverse();
    test.inorderTraverse();


    return 0;
}


/**
* Fills binary search tree with
* random values between 0 and 200
* @param        BinarySearchTree object
**/
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
