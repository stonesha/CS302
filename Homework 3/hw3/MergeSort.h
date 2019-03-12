#ifndef MERGESORT_H
#define MERGESORT_H

#include <iostream>
#include <random>
#include <algorithm>
#include <time.h>

template <typename T>
class MergeSort
{
    public:
        MergeSort(int sizeVal);
        virtual ~MergeSort();

        void serialize();

        void sort(int l, int r);
        void merge(int start, int mid, int end);

        void deallocate();

    protected:

    private:
        T *arr;
        int size;

        float seconds = 0;
        int clicks = 0;

        size_t comparisons = 0;
        size_t swaps = 0;
};


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

template <typename T>
MergeSort<T>::~MergeSort()
{
    delete[] arr;
    arr = nullptr;
}

template <typename T>
void MergeSort<T>::deallocate()
{
    delete[] arr;
    arr = nullptr;
}

template <typename T>
void MergeSort<T>::serialize()
{
    seconds = ((float(clicks)/CLOCKS_PER_SEC));

    for(int i = 0; i < size; i++)
    {
        if(i % 10 == 0)
            std::cout << std::endl;
        std::cout << arr[i] << ", ";
    }

    std::cout << std::endl << "The sorting took "
        << clicks << " clicks and "
        << seconds << " seconds." << std::endl;

    std::cout << "There were "
        << comparisons << " comparisons and "
        << swaps << " swaps." << std::endl;
}

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
}


#endif // MERGESORT_H
