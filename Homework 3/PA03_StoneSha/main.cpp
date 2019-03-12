/**
 * @brief  CS-302 Homework 3
 * @Author Stone Sha (stones@nevada.unr.edu)
 * @date   March 2019
 *
 * This file is the main file for testing sorts (Bubble and Merge)
 */
#include "BubbleSort.h"
#include "MergeSort.h"

int main()
{
    //values needed for menu/switch statements
    int sortOption = 0, valueOption = 0;
    bool menu = true;

    while(menu)//while loop to keep menu running until exited
    {
        //options
        std::cout << std:: endl << "Which sort would you like to test?" << std::endl
                  << "(1) BubbleSort" << std::endl
                  << "(2) MergeSort" << std::endl
                  << "(3) Quit Program" <<std::endl;
        std::cin >> sortOption;
        switch(sortOption)
        {
            //BUBBLESORT
            case 1:
            std::cout << "=====BUBBLESORT=====" << std::endl
                      << "(1) Thousand" << std::endl
                      << "(2) Ten Thousand" << std::endl
                      << "(3) Hundred Thousand" << std::endl;
            std::cin >> valueOption;

                switch(valueOption)//SWITCH 1
                {
                case 1:
                    {
                        std::cout << "=====TESTING THOUSAND VALUES=====" << std::endl;
                        BubbleSort<int> Bthousand(1000);

                        Bthousand.sort();

                        Bthousand.serialize();

                        Bthousand.deallocate();
                    }
                break;



                case 2:
                    {
                        std::cout << "=====TESTING TEN THOUSAND VALUES=====" << std::endl;
                        BubbleSort<int> BtenThousand(10000);

                        BtenThousand.sort();

                        BtenThousand.serialize();

                        BtenThousand.deallocate();
                    }
                break;

                case 3:
                    {
                        std::cout << "=====TESTING ONE HUNDRED THOUSAND VALUES=====" << std::endl;
                        BubbleSort<int> BhundredThousand(100000);

                        BhundredThousand.sort();

                        BhundredThousand.serialize();

                        BhundredThousand.deallocate();
                    }
                break;

                default:
                    std::cout << "Invalid Option" << std::endl;
                break;
                }//END OF SWITCH 1
                break;//END OF CASE 1

        //QUICKSORT
        case 2:
            std::cout << "=====MERGESORT=====" << std::endl
                      << "(1) Thousand" << std::endl
                      << "(2) Ten Thousand" << std::endl
                      << "(3) Hundred Thousand" << std::endl;
            std::cin >> valueOption;
            switch(valueOption)//SWTICH 2
            {
            case 1:
                {
                    std::cout << "=====TESTING THOUSAND VALUES=====" << std::endl;

                    MergeSort<int> Mthousand(1000);

                    Mthousand.sort(0, 1000);

                    Mthousand.serialize();

                    Mthousand.deallocate();
                }
                break;

            case 2:
                {
                    std::cout << "=====TESTING TEN THOUSAND VALUES=====" << std::endl;

                    MergeSort<int> MtenThousand(10000);

                    MtenThousand.sort(0, 10000);

                    MtenThousand.serialize();

                    MtenThousand.deallocate();
                }
                break;

            case 3:
                {
                    std::cout << "=====TESTING ONE HUNDRED THOUSAND VALUES=====" << std::endl;

                    MergeSort<int> MhundredThousand(100000);

                    MhundredThousand.sort(0, 100000);

                    MhundredThousand.serialize();

                    MhundredThousand.deallocate();

                }
                break;

            default:
                std::cout << "Invalid Option" << std::endl;
                break;
            }//END OF SWITCH 2
            break;//END OF CASE 2

        case 3:
            menu = false;
            break;

        default:
            std::cout << "Invalid Option" << std::endl;
            break;
        }//END OF SWITCH
    }//END OF WHILE











    return 0;
}

