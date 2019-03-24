/**
 * @file BinarySearchTree.h
 * @author Stone Sha (stones@nevada.unr.edu)
 * @date March, 2019
 * @brief Class file for BinarySearchTree, self-contained header
 */
#ifndef BINARY_SEARCH_TREE_
#define BINARY_SEARCH_TREE_

#include <memory> // std::shared_ptr
#include <stdexcept> // std::throw, std::logic_error
#include <random> //random_device, mt199937, uniform_int_distribution
#include <algorithm> //std::max
#include "BinaryNode.h"

template<class ItemType>
class BinarySearchTree
{
private:
    std::shared_ptr<BinaryNode<ItemType>> rootPtr;

protected:
//------------------------------------------------------------
// Protected Utility Methods Section:
// Recursive helper methods for the public methods.
//------------------------------------------------------------

    std::shared_ptr<BinaryNode<ItemType>>
                                       placeNode(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                                               std::shared_ptr<BinaryNode<ItemType>> newNodePtr);


    void preorderHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const;

    void inorderHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const;

    void postorderHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const;

    int heightHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr);

public:
//------------------------------------------------------------
// Constructor and Destructor Section.
//------------------------------------------------------------
    BinarySearchTree();
    virtual ~BinarySearchTree();

//------------------------------------------------------------
// Public Methods Section.
//------------------------------------------------------------
    int getHeight();
    bool isEmpty() const;

    bool add(const ItemType& newEntry);

    bool remove(const ItemType& target);

//------------------------------------------------------------
// Public Traversals Section.
//------------------------------------------------------------

    void preorderTraverse() const;
    void inorderTraverse() const;
    void postorderTraverse() const;

}; // end BinarySearchTree


//------------------------------------------------------------
// Protected Methods Implementation
//------------------------------------------------------------

/**
*
* @param
**/
template<class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType& newEntry)
{

    auto newNodePtr = std::make_shared<BinaryNode<ItemType>> (newEntry);
    rootPtr = placeNode(rootPtr, newNodePtr);

    return true;
}

/**
*
* @param
**/
template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>>
                                   BinarySearchTree<ItemType>::
                                   placeNode(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                                           std::shared_ptr<BinaryNode<ItemType>> newNodePtr)
{
    std::shared_ptr<BinaryNode<ItemType>> tempPtr;

    if(subTreePtr == nullptr)
    {
        return newNodePtr;
    }
    else if(subTreePtr->getItem() > newNodePtr->getItem())
    {
        tempPtr = placeNode(subTreePtr->getLeftChildPtr(), newNodePtr);
        subTreePtr->setLeftChildPtr(tempPtr);
    }
    else
    {
        tempPtr = placeNode(subTreePtr->getRightChildPtr(), newNodePtr);
        subTreePtr->setRightChildPtr(tempPtr);
    }

    return subTreePtr;
}

/**
*
* @param
**/
template<class ItemType>
int BinarySearchTree<ItemType>::heightHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr)
{
    if(subTreePtr == nullptr)
        return 1;

    return 1 + std::max(heightHelper(subTreePtr->getLeftChildPtr()),
                   heightHelper(subTreePtr->getRightChildPtr()));
}

//------------------------------------------------------------
// Constructor and Destructor Section.
//------------------------------------------------------------

/**
* Constructor for BinarySearchTree sets rootPtr to nullptr
* indicating an empty tree
**/
template<class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree() : rootPtr(nullptr)
{
}//end constructor

template<class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree()
{
}//end destructor

//------------------------------------------------------------
// Public Methods Section.
//------------------------------------------------------------
/**
*
* @param
**/
template<class ItemType>
int BinarySearchTree<ItemType>::getHeight()
{
    return heightHelper(rootPtr);
}

/**
*
* @param
**/
template<class ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const
{
    return rootPtr == nullptr;
}

//------------------------------------------------------------
// Public Traversals Section.
//------------------------------------------------------------

/**
*
* @param
**/
template<class ItemType>
void BinarySearchTree<ItemType>::
preorderHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const
{
    if(subTreePtr == nullptr)
        return;


    std::cout << subTreePtr->getItem() << " ";

    preorderHelper(subTreePtr->getLeftChildPtr());

    preorderHelper(subTreePtr->getRightChildPtr());

}

/**
*
* @param
**/
template<class ItemType>
void BinarySearchTree<ItemType>::
inorderHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const
{

    if(subTreePtr == nullptr)
        return;

    inorderHelper(subTreePtr->getLeftChildPtr());

    std::cout << subTreePtr->getItem() << " ";

    inorderHelper(subTreePtr->getRightChildPtr());

}

/**
*
* @param
**/
template<class ItemType>
void BinarySearchTree<ItemType>::
postorderHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const
{

    if(subTreePtr == nullptr)
        return;

    postorderHelper(subTreePtr->getLeftChildPtr());

    postorderHelper(subTreePtr->getRightChildPtr());

    std::cout << subTreePtr->getItem() << " ";

}


/**
*
* @param
**/
template<class ItemType>
void BinarySearchTree<ItemType>::preorderTraverse() const
{
    std::cout << std::endl << "===== Preorder =====" << std::endl;

    preorderHelper(rootPtr);
}

/**
*
* @param
**/
template<class ItemType>
void BinarySearchTree<ItemType>::inorderTraverse() const
{
    std::cout << std::endl << "===== Inorder =====" << std::endl;

    inorderHelper(rootPtr);
}

/**
*
* @param
**/
template<class ItemType>
void BinarySearchTree<ItemType>::postorderTraverse() const
{
    std::cout << std::endl << "===== Postorder =====" << std::endl;

    postorderHelper(rootPtr);
}

#endif
