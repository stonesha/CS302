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
    BinaryNode();

    BinaryNode(const ItemType& anItem);

    BinaryNode(const ItemType& anItem,
               std::shared_ptr<BinaryNode<ItemType>> leftPtr,
               std::shared_ptr<BinaryNode<ItemType>> rightPtr);

    void setItem(const ItemType& anItem);
    ItemType getItem() const;

    bool isLeaf() const;

    auto getLeftChildPtr() const;
    auto getRightChildPtr() const;

    void setLeftChildPtr(std::shared_ptr<BinaryNode<ItemType>> leftPtr);
    void setRightChildPtr(std::shared_ptr<BinaryNode<ItemType>> rightPtr);

}; // end BinaryNode

template<class ItemType>
BinaryNode<ItemType>::BinaryNode() :
    leftChildPtr(nullptr),
    rightChildPtr(nullptr)
{
}

template<class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem) :
    item(anItem),
    leftChildPtr(nullptr),
    rightChildPtr(nullptr)
{
}

template<class ItemType>
BinaryNode<ItemType>::BinaryNode(const ItemType& anItem,
           std::shared_ptr<BinaryNode<ItemType>> leftPtr,
           std::shared_ptr<BinaryNode<ItemType>> rightPtr) :
    item(anItem),
    leftChildPtr(leftPtr),
    rightChildPtr(rightPtr)
{
}

template<class ItemType>
void BinaryNode<ItemType>::setItem(const ItemType& anItem)
{
    item = anItem;
}

template<class ItemType>
ItemType BinaryNode<ItemType>::getItem() const
{
    return item;
}

template<class ItemType>
bool BinaryNode<ItemType>::isLeaf() const
{
   return ((leftChildPtr == nullptr) &&
           (rightChildPtr == nullptr));
}

template<class ItemType>
auto BinaryNode<ItemType>::getLeftChildPtr() const
{
    return leftChildPtr;
}

template<class ItemType>
auto BinaryNode<ItemType>::getRightChildPtr() const
{
    return rightChildPtr;
}

template<class ItemType>
void BinaryNode<ItemType>::setLeftChildPtr(std::shared_ptr<BinaryNode<ItemType>> leftPtr)
{
    leftChildPtr = leftPtr;
}

template<class ItemType>
void BinaryNode<ItemType>::setRightChildPtr(std::shared_ptr<BinaryNode<ItemType>> rightPtr)
{
    rightChildPtr = rightPtr;
}

#endif
