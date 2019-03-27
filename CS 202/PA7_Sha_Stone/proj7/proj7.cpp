/**
 * @brief  CS-202 Project 7 MyString class source
 * @Author Stone Sha (stones@nevada.unr.edu)
 * @date   October, 2018
 *
 * This file is the test driver for Project 7
 */

#include "MyString.h"

int main()
{

    //(1)
    MyString ms_default;

    //(2)
    MyString ms_parametrized("MyString parametrized constructor!");
    cout << ms_parametrized << endl;

    //(3)
    MyString ms_copy(ms_parametrized);
    cout << ms_copy << endl;

    //(4)
    MyString * ms_Pt = new MyString("MyString to be deleted…");
    ms_Pt = NULL;
    delete ms_Pt;
    ms_Pt = NULL;

       //(5),(6)
    MyString ms_size_length("Size and length test");
    cout << ms_size_length.size() << endl;
    cout << ms_size_length.length() << endl;

    //(7)
    MyString ms_toCstring("C-String equivalent successfully obtained!");
    cout << ms_toCstring.c_str() << endl;

    //(8)
    MyString ms_same1("The same"), ms_same2("The same");
    if (ms_same1==ms_same2)
        cout << "Same success" << endl;
    MyString ms_different("The same (NOT)");
    if (!(ms_same1==ms_different))
        cout << "Different success" << endl;

    //(9)
    MyString ms_assign("Before assignment");
    cout << ms_assign << endl;
    ms_assign = MyString("After performing assignment");
    cout << ms_assign << endl;

    //(10)
    MyString ms_append1("The first part");
    MyString ms_append2(" and the second");
    MyString ms_concat = ms_append1 + ms_append2;
    cout << ms_concat << endl;

    //(11)
    MyString ms_access("Access successful (NOT)");
    ms_access[17] = 0;

    //12
    cout << ms_access << endl;


    return 0;
}
