/*
 * =====================================================================================
 *
 *       Filename:  transform.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/10/2014 03:48:43 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */


#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int square(int value)
{
    return value*value;
}

template <class T>
inline void PRINT_ELEM(const T& coll, const char* optcstr="")
{
    typename T::const_iterator pos;
    std::cout << optcstr << std::endl;
    for (pos=coll.begin(); pos!=coll.end(); ++pos) {
        std::cout << *pos << ' ';
    }
    std::cout << std::endl;
}

int main(void)
{
    std::set<int> coll1;
    std::vector<int> coll2;

    for (int i=1; i<=9; i++) {
        coll1.insert(i);
    }
    PRINT_ELEM(coll1, "initialized: ");

    std::transform(coll1.begin(), coll1.end(), std::back_inserter(coll2), square);
    PRINT_ELEM(coll2, "square: ");  

}
