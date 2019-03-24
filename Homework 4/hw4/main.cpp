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

void randGen(BinarySearchTree<int> &bst);

int main()
{

    BinarySearchTree<int> test;
    //initialization for random ints

    randGen(test);

    std::cout << "Height: " << test.getHeight() << std::endl;

    /*
    test.preorderTraverse();
    test.postorderTraverse();
    test.inorderTraverse();
    */

    return 0;
}


void randGen(BinarySearchTree<int> &bst)
{
    //initialization for random ints
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 200);

    for(int i = 0; i < 5; i++)
    {
        bst.add(dis(gen));
    }
}
