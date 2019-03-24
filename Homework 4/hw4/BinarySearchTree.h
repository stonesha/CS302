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

    int getHeightHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const;

    std::shared_ptr<BinaryNode<ItemType>>
                                       sortedAdd(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                                               std::shared_ptr<BinaryNode<ItemType>> newNodePtr);

    auto destroyTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr);


    void preorderHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const;

    void inorderHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const;

    void postorderHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const;

public:
//------------------------------------------------------------
// Constructor and Destructor Section.
//------------------------------------------------------------
    BinarySearchTree();
    virtual ~BinarySearchTree();

//------------------------------------------------------------
// Public Methods Section.
//------------------------------------------------------------
    bool isEmpty() const;
    int getHeight() const;

    bool add(const ItemType& newEntry);

    bool remove(const ItemType& target);
    void clear();

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
int BinarySearchTree<ItemType>::
getHeightHelper(std::shared_ptr<BinaryNode<ItemType>> subTreePtr) const
{
    if(rootPtr == nullptr)
        return 0;

    return 1 + std::max(getHeightHelper(subTreePtr->getLeftChildPtr()),
                        getHeightHelper(subTreePtr->getRightChildPtr()));
}

/**
*
* @param
**/
template<class ItemType>
std::shared_ptr<BinaryNode<ItemType>>
                                   BinarySearchTree<ItemType>::
                                   sortedAdd(std::shared_ptr<BinaryNode<ItemType>> subTreePtr,
                                           std::shared_ptr<BinaryNode<ItemType>> newNodePtr)
{
    std::shared_ptr<BinaryNode<ItemType>> tempPtr;

    if(subTreePtr == nullptr)
    {
        return newNodePtr;
    }
    else if(subTreePtr->getItem() > newNodePtr->getItem())
    {
        subTreePtr->setLeftChildPtr(sortedAdd(subTreePtr->getLeftChildPtr(), newNodePtr));
    }
    else
    {
        subTreePtr->setRightChildPtr(sortedAdd(subTreePtr->getRightChildPtr(), newNodePtr));
    }

    return subTreePtr;
}

/**
*
* @param
**/
template<class ItemType>
auto BinarySearchTree<ItemType>::destroyTree(std::shared_ptr<BinaryNode<ItemType>> subTreePtr)
{
    if(subTreePtr == nullptr)
        return;

    subTreePtr = nullptr;

    destroyTree(subTreePtr->getLeftChildPtr());
    destroyTree(subTreePtr->getRightChildPtr());
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

/**
*
* @param
**/
template<class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree()
{
    clear();
}


//------------------------------------------------------------
// Public Methods Section.
//------------------------------------------------------------

/**
*
* @param
**/
template<class ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const
{
    return rootPtr == nullptr;
}

/**
*
* @param
**/
template<class ItemType>
int BinarySearchTree<ItemType>::getHeight() const
{
    return getHeightHelper(rootPtr);
}

/**
*
* @param
**/
template<class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType& newEntry)
{

    auto newNodePtr = std::make_shared<BinaryNode<ItemType>>(newEntry);
    rootPtr = sortedAdd(rootPtr, newNodePtr);

    return true;
}

/**
*
* @param
**/
template<class ItemType>
void BinarySearchTree<ItemType>::clear()
{
    if (rootPtr != nullptr)
    {
        destroyTree(rootPtr->getLeftChildPtr());
        destroyTree(rootPtr->getRightChildPtr());
        rootPtr.reset(); //decrement reference count to node;
    }
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
    if(isEmpty())
    {
        std::cout << "Empty" << std::endl;
        return;
    }


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

    if(isEmpty())
    {
        std::cout << "Empty" << std::endl;
        return;
    }

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
    if(isEmpty())
    {
        std::cout << "Empty" << std::endl;
        return;
    }

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
    std::cout << "===== Preorder =====" << std::endl;

    preorderHelper(rootPtr);
}

/**
*
* @param
**/
template<class ItemType>
void BinarySearchTree<ItemType>::inorderTraverse() const
{
    std::cout << "===== Inorder =====" << std::endl;

    inorderHelper(rootPtr);
}

/**
*
* @param
**/
template<class ItemType>
void BinarySearchTree<ItemType>::postorderTraverse() const
{
    std::cout << "===== Postorder =====" << std::endl;

    postorderHelper(rootPtr);
}

#endif
