/**
 * @brief  CS-202 Project 10 Test Driver
 * @Author Stone Sha (stones@nevada.unr.edu)
 * @date   December, 2018
 *
 * This file is the header file for the vector recursion functions
 */
#ifndef VECTORRECURSION_H
#define VECTORRECURSION_H

#include <vector>

template <class T>
//for printing out the contents of a vector for conveniences sake
void printVec(std::vector<T> &v)
{
    for(typename std::vector<T>::const_iterator i = v.begin(); i != v.end(); i++)
    {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}

template <class T>
//partition function to help with quick sorting
//start for beginning, end for ending/last
T vector_partition(std::vector<T> &v, T s, T e)
{
    T pivot = v[s];
    T left = s + 1;
    T right = e;
    T temp;

    while(left != right)
    {
        if(v[left] <= pivot)
            left++;
        else
        {
            while((left != right) && (pivot < v[right]))
                right--;

            //swap values
            temp = v[right];
            v[right] = v[left];
            v[left] = temp;
        }
    }

    if(v[left] > pivot)
        left--;
    v[s] = v[left];
    v[left] = pivot;

    return left;
}

template <class T>
//vector quicksort function
//vec for vector, l for low, h for high
void vector_resort(std::vector<T> &v, T l, T h)
{
    if(l < h)
    {
        T num = vector_partition(v, l, h);
        vector_resort(v, l, num - 1);
        vector_resort(v, num + 1, h);
    }
}

template <class T>
//for convenience sake, also includes check
void vector_resort(std::vector<T> &v)
{
    T vecSize = v.size();
    if(vecSize > 1)
        vector_resort(v, 0, vecSize - 1);
}

template <class T>
//recursive binary search
//s being start, e being the ending, x being the item searched for
T vector_research(std::vector<T> &v, T s, T e, T x)
{

    //pivot being at middle of array or comparatively to start


    //check for failure
    if(s <= e)
    {
        T pivot = s + (e - s + 1)/2;

        //if anything is equal to item
        if(v[pivot] == x)
            return pivot;
        else if(v[s] == x)
            return s;
        else if(v[e] == x)
            return e;

        else if(v[pivot] < x)
            return vector_research(v, pivot + 1, e, x);
        else if(v[pivot] > x)
            return vector_research(v, s, pivot - 1, x);
    }

    // item not present;
    return -1;
}

template <class T>
T vector_research(std::vector<T> &v, T x)
{
    T vecSize = v.size();
    T index;
    if(vecSize > 1)
        index = vector_research(v, 0, vecSize, x);

    return index;
}

#endif // VECTORRECURSION_H


