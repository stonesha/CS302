#ifndef MERGESORT_H
#define MERGESORT_H

#include <iostream>
#include <random>
#include <algorithm>
#include <vector>

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

    for(int i = 0; i < size; i++)
    {
        if(i % 10 == 0)
            std::cout << std::endl;
        std::cout << arr[i] << ", ";
    }
}

template <typename T>
void MergeSort<T>::merge(int start, int mid, int end)
{
    int start2 = mid + 1;

    // If the direct merge is already sorted
    if (arr[mid] <= arr[start2])
    {
        return;
    }

    // Two pointers to maintain start
    // of both arrays to merge
    while (start <= mid && start2 <= end)
    {

        // If element 1 is in right place
        if (arr[start] <= arr[start2])
        {
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
                arr[index] = arr[index - 1];
                index--;
            }
            arr[start] = value;

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
    if (front < end)
    {

        // Same as (l + r) / 2, but avoids overflow
        // for large l and r
        int mid = front + (end - front) / 2;

        // Sort first and second halves
        sort(front, mid);
        sort(mid + 1, end);
        merge(front, mid, end);
    }
}


#endif // MERGESORT_H
