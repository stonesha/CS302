/**
 * @file main.cpp
 * @author Stone Sha (stones@nevada.unr.edu)
 * @date March, 2019
 * @brief Test program for Heap ADT using STL
 */
#include <iostream>
#include <algorithm> //  std::make_heap,  std::pop_heap,  std::push_heap,  std::sort_heap
#include <vector> // std::vector
#include <numeric>  // std::accumulate
#include <random> //std::random_device, std::mt199937, std::uniform_int_distribution
#include <chrono> // std::chrono::system_clock

//using namespace for convenience sake since this program is small
using namespace std;

//prototyping for functions that help
void randGen(vector<int> &vec);
void printVec(vector<int> vec);

int main()
{

    //vector initialized
    vector<int> v;

    //random values in vector
    randGen(v);

    cout <<  endl << "=====Randomly Generated Vector=====";

    printVec(v);

    //makes vector a heap
    make_heap(v.begin(), v.end());

    //checks if it's actually a heap
    if(is_heap(v.begin(), v.end()))
        cout <<  endl << "=====Vector is now a Heap=====";

    //calculates mean using std::accumulate
    auto mean =  accumulate(v.begin(), v.end(), 0) / v.size();

    //pushes mean into heap
    v.push_back(mean);
    push_heap(v.begin(), v.end());

    cout <<  endl  << "=====Mean pushed onto Heap=====" << endl;
    cout << "Mean is " << mean;
    printVec(v);

    //moves maximum element to back of vector
    pop_heap(v.begin(), v.end());
    //removes maximum element at the back
    v.pop_back();

    cout <<  endl  << "=====Maximum Element Deleted=====";

    printVec(v);

    //sorts heap in ascending order
    sort_heap(v.begin(), v.end());

    cout <<  endl  << "=====Sorted Heap=====";

    printVec(v);
    cout << endl;

    return 0;
}


/**
* Fills vector with
* random values between 0 and 200
* @param        vector<int> vec
**/
void randGen(vector<int> &vec)
{
    //initialization for random
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 300);
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();

    //fills vector with values within range
    for(int i = 0;i < 100; i++)
        vec.push_back(dis(gen));

    shuffle(vec.begin(), vec.end(), default_random_engine(seed));

}

/**
* Prints values of vector
* @param        vector<int> vec
**/
void printVec(vector<int> vec)
{
    cout <<  endl;

    for(unsigned int i = 0; i < vec.size(); i++)
    {
        if(i % 10 == 0)
            cout <<  endl;

        cout  << vec[i] << ", ";
    }
}
