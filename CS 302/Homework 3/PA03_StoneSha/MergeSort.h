/**
 * @brief  CS-302 Homework 3
 * @Author Stone Sha (stones@nevada.unr.edu)
 * @date   March 2019
 *
 * Self contained templated header file for Merge sorting
 */
#ifndef MERGESORT_H
#define MERGESORT_H

#include <iostream>
#include <random> //random_device, mt199937, uniform_int_distribution
#include <algorithm> //std::swap
#include <time.h> //clock_t, clock(), CLOCKS_PER_SEC

template <typename T>
class MergeSort
{
    //public members/methods
    public:
        MergeSort(int sizeVal);
        virtual ~MergeSort();

        void serialize() const;

        void sort(int l, int r);
        void merge(int start, int mid, int end);

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
 * Parameterized constructor for MergeSort class
 * fills dynamic array with random values
 * @param size of array
 */
template <typename T>
MergeSort<T>::MergeSort(int sizeVal)
{
    //dynamically allocate memory then insert random values

    //initialization for random ints
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 1000000);

    arr = new (std::nothrow) int [sizeVal];
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
MergeSort<T>::~MergeSort()
{
    deallocate();
}

/**
 * Deallocation method for BubbleSort class
 */
template <typename T>
void MergeSort<T>::deallocate()
{
    delete[] arr;
    arr = nullptr;
}

/**
 * Used to print values of the array
 * also prints time, comparisons, and swaps
 */
template <typename T>
void MergeSort<T>::serialize() const
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
void MergeSort<T>::merge(int start, int mid, int end)
{
    int start2 = mid + 1;
    clock_t t;

    t = clock();
    // If the direct merge is already sorted
    if (arr[mid] <= arr[start2])
    {
        comparisons++;
        t = clock() - t;
        clicks += t;
        return;
    }

    // Two pointers to maintain start
    // of both arrays to merge
    while (start <= mid && start2 <= end)
    {
        comparisons++;
        // If element 1 is in right place
        if (arr[start] <= arr[start2])
        {
            comparisons++;
            start++;

        }
        else
        {
            int value = arr[start2];
            int index = start2;

            // Shift all the elements between element 1
            // element 2, right by 1.
            while (index != start)
            {
                comparisons++;
                arr[index] = arr[index - 1];
                swaps++;
                index--;
            }
            arr[start] = value;
            swaps++;

            // Update all the pointers
            start++;
            mid++;
            start2++;
        }
    }
} // end merge


template <typename T>
void MergeSort<T>::sort(int front, int end)
{
    clock_t t;
    t = clock();

    if (front < end)
    {
        comparisons++;

        // Same as (l + r) / 2, but avoids overflow
        // for large l and r
        int mid = front + (end - front) / 2;

        // Sort first and second halves
        sort(front, mid);
        sort(mid + 1, end);
        merge(front, mid, end);
    }
    t = clock() - t;

    clicks += t;
    seconds = ((float(clicks)/CLOCKS_PER_SEC));
}


#endif // MERGESORT_H
