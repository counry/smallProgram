/*
 * =====================================================================================
 *
 *       Filename:  setcmp.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/15/2014 02:47:41 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <set>

using namespace std;

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

