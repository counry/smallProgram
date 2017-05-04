/*
 * =====================================================================================
 *
 *       Filename:  numeric_limits.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/10/2014 10:16:22 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <limits>
#include <string>

using namespace std;

int main(void)
{
    cout << boolalpha;  //功能是把bool值显示为true或false

    cout << "max(short): " << numeric_limits<short>::max() << endl;
    cout << "max(int): " << numeric_limits<int>::max() << endl;
    cout << "max(long): " << numeric_limits<long>::max() << endl;
    cout << endl;

    cout << "max(float): " << numeric_limits<float>::max() << endl;
    cout << "max(double): " << numeric_limits<double>::max() << endl;
    cout << "max(long double): " << numeric_limits<long double>::max() << endl;
    cout << endl;

    cout << "is_signed(char): " << numeric_limits<char>::is_signed << endl;
    cout << endl;

    cout << "is_specialized(string): " << numeric_limits<string>::is_specialized << endl;

    return 0;
}

