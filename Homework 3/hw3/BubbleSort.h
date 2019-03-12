#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <iostream>
#include <random>
#include <algorithm>

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
        int *arr;
        int size;
};

#endif // SELECTIONSORT_H
