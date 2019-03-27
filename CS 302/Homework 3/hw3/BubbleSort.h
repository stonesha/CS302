/**
 * @brief  CS-302 Homework 3
 * @Author Stone Sha (stones@nevada.unr.edu)
 * @date   March 2019
 *
 * Self contained templated header file for Bubble sorting
 */
#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <iostream>
#include <random> //random_device, mt199937, uniform_int_distribution
#include <algorithm> //std::swap
#include <time.h> //clock_t, clock(), CLOCKS_PER_SEC

template <typename T>
class BubbleSort
{
    //public members/methods
    public:
        BubbleSort(int sizeVal);
        virtual ~BubbleSort();

        void serialize() const;
        void sort();
        void deallocate();

    //private members/methods
    private:
        //members for array
        T *arr;
        int size;

        //members for time
        float seconds = 0;
        int clicks = 0;

        //members for comparisons and swaps
        size_t comparisons = 0;
        size_t swaps = 0;
};

/**
 * Parameterized constructor for BubbleSort class
 * fills dynamic array with random values
 * @param size of array
 */
template <typename T>
BubbleSort<T>::BubbleSort(int sizeVal)
{
    //dynamically allocate memory then insert random values

    //initialization for random ints
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1000000);

    //resizes vector and sets size
    arr = new (std::nothrow) T [sizeVal];
    size = sizeVal;

    //fills vector with random values
    for(int i = 0; i < size; i++)
    {
        arr[i] = dis(gen);
    }

}

/**
 * Destructor for BubbleSort class
 */
template <typename T>
BubbleSort<T>::~BubbleSort()
{
    //dtor
    deallocate();
}

/**
 * Deallocation method for BubbleSort class
 */
template <typename T>
void BubbleSort<T>::deallocate()
{
    delete[] arr;
    arr = nullptr;
}

/**
 * Used to print values of the array
 * also prints time, comparisons, and swaps
 */
template <typename T>
void BubbleSort<T>::serialize() const
{
    for(int i = 0; i < size; i++)
    {
        if(i % 10 == 0)
            std::cout << std::endl;
        std::cout << arr[i] << ", ";
    }

    //prints out clicks and seconds
    std::cout << std::endl << "The sorting took "
        << clicks << " clicks and "
        << seconds << " seconds." << std::endl;

    //prints out comparisons and swaps
    std::cout << "There were "
        << comparisons << " comparisons and "
        << swaps << " swaps." << std::endl;
}

/**
 * Actual method for sorting
 * copied from lecture slides with a few changes
 * primarily added comparison and swap increments
 * also added time keeping
 */
template <typename T>
void BubbleSort<T>::sort()
{
    bool swapped = false;

    clock_t t;
    t = clock();

    for(int i = 0; i < size - 1; i++)
    {
        swapped = false;
        for(int j = 0; j < size - 1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                comparisons++;
                std::swap(arr[j], arr[j+1]);
                swaps++;
                swapped = true;
            }
        }

        if(!swapped)
            break;
    }

    t = clock() - t;

    clicks = t;

    seconds = ((float(t)/CLOCKS_PER_SEC));

}


#endif // SELECTIONSORT_H
