/**
 * @file LLRBT.h
 * @author Stone Sha (stones@nevada.unr.edu)
 * @date April, 2019
 * @brief Class file for Left Leaning Red-Black Tree, self-contained header
 */

#pragma once
#include <iostream>
#include "RBNODE.hpp"

template <class ItemType>
class LLRBT
{
private:
    RBNODE<ItemType>* rootPtr;

protected:

    auto insertRec(RBNODE<ItemType> *pNode1, RBNODE<ItemType> *pNode2);

    void Free(RBNODE<ItemType>* pNode);

    auto rotateLeft(RBNODE<ItemType>* pNode);
    auto rotateRight(RBNODE<ItemType>* pNode);

    bool isRed(auto pNode);
    void swapColors(auto pNode1, auto pNode2);

    //traversal
    void inorderHelper(auto pNode);

public:

LLRBT(void);
~LLRBT(void);

void add(const ItemType &anItem);
void remove(const ItemType &entry);

void inorder();

};

/////////////////////////////////////////////////////////////////////////////
//
//  Constructors and Destructors
//
template <class ItemType>
LLRBT<ItemType>::LLRBT(void) : rootPtr(nullptr)
{
}

template <class ItemType>
LLRBT<ItemType>::~LLRBT(void)
{
    Free(rootPtr);
}

/////////////////////////////////////////////////////////////////////////////
//
//  Public Methods
//

template <class ItemType>
void LLRBT<ItemType>::add(const ItemType &anItem)
{
    RBNODE<ItemType> *pNode = new RBNODE<ItemType> (anItem);
    rootPtr = insertRec(rootPtr, pNode);
    rootPtr->setColor(false);
}

template <class ItemType>
void LLRBT<ItemType>::inorder(void)
{
    std::cout << std::endl << "=====INORDER TRAVERSAL=====" << std::endl;
    inorderHelper(rootPtr);
    std::cout << std::endl;
}

/////////////////////////////////////////////////////////////////////////////
//
//  Protected Methods
//
template <class ItemType>
void LLRBT<ItemType>::Free(RBNODE<ItemType>* pNode)
{
    if(pNode != nullptr)
    {
        if(pNode->getLeftChildPtr() != nullptr)
        {
            Free(pNode->getLeftChildPtr());
        } else if (pNode->getRightChildPtr() != nullptr)
        {
            Free(pNode->getRightChildPtr());
        }

        delete pNode;
        pNode = nullptr;
    }
}

template <class ItemType>
auto LLRBT<ItemType>::rotateLeft(RBNODE<ItemType>* pNode)
{
    auto pChildRight = pNode->getRightChildPtr();
    pNode->setRightChildPtr(pChildRight->getLeftChildPtr());
    pChildRight->setLeftChildPtr(pNode);
    pChildRight->setColor(pNode->getColor());
    pNode->setColor(true);

    return pChildRight;
}

template <class ItemType>
auto LLRBT<ItemType>::rotateRight(RBNODE<ItemType>* pNode)
{
    auto pChildLeft = pNode->getLeftChildPtr();
    pNode->setLeftChildPtr(pChildLeft->getRightChildPtr());
    pChildLeft->setRightChildPtr(pNode);
    pChildLeft->setColor(pNode->getColor());
    pNode->setColor(true);

    return pChildLeft;
}

template <class ItemType>
bool LLRBT<ItemType>::isRed(auto pNode)
{
    return (pNode->getColor() == true);
}

template <class ItemType>
void LLRBT<ItemType>::swapColors(auto pNode1, auto pNode2)
{
    bool color1 = pNode1->getColor(), color2 = pNode2->getColor();

    pNode1->setColor(color1);
    pNode2->setColor(color2);

}

template <class ItemType>
auto LLRBT<ItemType>::insertRec(RBNODE<ItemType> *pNode1, RBNODE<ItemType> *pNode2)
{
    if(pNode1 == nullptr)
        return pNode2;


    if(pNode2->getItem() < pNode1->getItem())
        pNode1->setLeftChildPtr(insertRec(pNode1->getLeftChildPtr(), pNode2));

    else if(pNode2->getItem() > pNode1->getItem())
        pNode1->setRightChildPtr(insertRec(pNode1->getRightChildPtr(), pNode2));


    //case 1: Right child = red and left child is black/doesn't exist
    if(isRed(pNode1->getRightChildPtr()) && !isRed(pNode1->getLeftChildPtr()))
    {
        //left rotate node to make tree valid
        pNode1 = rotateLeft(pNode1);
    }

    //case 2: left child and left grandchild are red
    if(isRed(pNode1->getLeftChildPtr()) && isRed(pNode1->getLeftChildPtr()->getLeftChildPtr()))
    {
        //right rotate to make tree valid
        pNode1 = rotateRight(pNode1);
    }

    //case 3: left and right child are both red
    if(isRed(pNode1->getLeftChildPtr()) && isRed(pNode1->getRightChildPtr()))
    {
        //invert color of node as well as it's left and right child
        pNode1->setColor(!(pNode1->getColor()));

        pNode1->getLeftChildPtr()->setColor(!(pNode1->getLeftChildPtr()->getColor()));
        pNode1->getRightChildPtr()->setColor(!(pNode1->getRightChildPtr()->getColor()));
    }

    return pNode1;
}

template <class ItemType>
void LLRBT<ItemType>::inorderHelper(auto pNode)
{
    //base case
    if(pNode == nullptr)
        return;

    inorderHelper(pNode->getLeftChildPtr());
    std::cout << pNode->getItem() << " (" << pNode->getTrueColor() << ") ";
    inorderHelper(pNode->getRightChildPtr());

}


