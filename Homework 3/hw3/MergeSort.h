#ifndef MERGESORT_H
#define MERGESORT_H

#include <iostream>
#include <random>
#include <algorithm>
#include <vector>

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
        int *arr;

        int size;
};

#endif // MERGESORT_H
