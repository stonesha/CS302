/**
 * @file main.cpp
 * @author Stone Sha (stones@nevada.unr.edu)
 * @date March, 2019
 * @brief Test driver for searching through Binary Trees
 */

#include <iostream>
#include <memory>

#include "BinaryNode.h"
#include "BinarySearchTree.h"


int main()
{

    BinarySearchTree<int> test;
    //initialization for random ints

    test.randGen();

    std::cout << "Height: " << test.getHeight() << std::endl;

    /*
    test.preorderTraverse();
    test.postorderTraverse();
    test.inorderTraverse();
    */

    return 0;
}

