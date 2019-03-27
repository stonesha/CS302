/**
 * @file BinaryNode.h
 * @author Stone Sha (stones@nevada.unr.edu)
 * @date March, 2019
 * @brief Class file for BinaryNode, self-contained header
 */

#ifndef BINARY_NODE_
#define BINARY_NODE_

#include <memory>

template<class ItemType>
class BinaryNode
{

private:
    ItemType item; // Data portion
    std::shared_ptr<BinaryNode<ItemType>> leftChildPtr; // Pointer to left child
    std::shared_ptr<BinaryNode<ItemType>> rightChildPtr; // Pointer to right child

public:
    //Constructors
    BinaryNode();

    BinaryNode(const ItemType& anItem);

    BinaryNode(const ItemType& anItem,
               std::shared_ptr<BinaryNode<ItemType>> leftPtr,
               std::shared_ptr<BinaryNode<ItemType>> rightPtr);

    //Public Getters and Setters/Methods
    void setItem(const ItemType& anItem);
    ItemType getItem() const;

    bool isLeaf() const;

    auto getLeftChildPtr() const;
    auto getRightChildPtr() const;

    void setLeftChildPtr(std::shared_ptr<BinaryNode<ItemType>> leftPtr);
    void setRightChildPtr(std::shared_ptr<BinaryNode<ItemType>> rightPtr);

}; // end BinaryNode

/**
* Constructor, sets left and right ptrs to null
**/
template<class ItemType>
BinaryNode<ItemType>::BinaryNode() :
    leftChildPtr(nullptr),
    rightChildPtr(nullptr)
{
}

/**
* Constructor, sets item to param and left and right to null
* @param    ItemType
**/
template<class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem) :
    item(anItem),
    leftChildPtr(nullptr),
    rightChildPtr(nullptr)
{
}

/**
* Constructor, sets left, right ptrs to param
* also sets anItem to param
* @param    ItemType
* @param    std::shared_ptr<BinaryNode<ItemType>>
* @param    std::shared_ptr<BinaryNode<ItemType>>
**/
template<class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem,
           std::shared_ptr<BinaryNode<ItemType>> leftPtr,
           std::shared_ptr<BinaryNode<ItemType>> rightPtr) :
    item(anItem),
    leftChildPtr(leftPtr),
    rightChildPtr(rightPtr)
{
}

/**
* sets Item to param
* @param    ItemType
**/
template<class ItemType>
void BinaryNode<ItemType>::setItem(const ItemType& anItem)
{
    item = anItem;
}

/**
* Gets Item
* @return ItemType
**/
template<class ItemType>
ItemType BinaryNode<ItemType>::getItem() const
{
    return item;
}

/**
* returns boolean value to check if node is a leaf
* @return boolean
**/
template<class ItemType>
bool BinaryNode<ItemType>::isLeaf() const
{
   return ((leftChildPtr == nullptr) &&
           (rightChildPtr == nullptr));
}

/**
* returns leftchildptr
* @return std::shared_ptr<BinaryNode<ItemType>>
**/
template<class ItemType>
auto BinaryNode<ItemType>::getLeftChildPtr() const
{
    return leftChildPtr;
}

/**
* returns rightchildptr
* @return std::shared_ptr<BinaryNode<ItemType>>
**/
template<class ItemType>
auto BinaryNode<ItemType>::getRightChildPtr() const
{
    return rightChildPtr;
}

/**
* sets leftchildptr
* @param std::shared_ptr<BinaryNode<ItemType>>
**/
template<class ItemType>
void BinaryNode<ItemType>::setLeftChildPtr(std::shared_ptr<BinaryNode<ItemType>> leftPtr)
{
    leftChildPtr = leftPtr;
}

/**
* sets right
* @param std::shared_ptr<BinaryNode<ItemType>>
**/
template<class ItemType>
void BinaryNode<ItemType>::setRightChildPtr(std::shared_ptr<BinaryNode<ItemType>> rightPtr)
{
    rightChildPtr = rightPtr;
}

#endif
