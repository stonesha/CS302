#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <iostream>
#include <random>
#include <algorithm>
#include <time.h>

template <typename T>
class BubbleSort
{
    public:
        BubbleSort(int sizeVal);
        virtual ~BubbleSort();

        void serialize();
        void sort();
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

template <typename T>
BubbleSort<T>::~BubbleSort()
{
    //dtor
    delete[] arr;
    arr = nullptr;
}

template <typename T>
void BubbleSort<T>::deallocate()
{
    delete[] arr;
    arr = nullptr;
}

template <typename T>
void BubbleSort<T>::serialize()
{
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
