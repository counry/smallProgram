/*
 * =====================================================================================
 *
 *       Filename:  pair.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/30/2014 11:44:58 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */


#include <iostream>

template <class T1, class T2>
struct pair {
    typedef T1 first_type;
    typedef T2 second_type;

    T1 first;
    T2 second;

    pair() : first(T1()), second(T2()) { }

    pair(const T1& a, const T2& b) : first(a), second(b) {}
};

template <class T1, class T2>
pair<T1, T2> make_pair(const T1& a, const T2& b)
{
    return pair<T1, T2>(a, b);
}


int main(void)
{
    int i = 10;
    int ii = 100;
    pair<int, int> p = make_pair(i, ii);
    std::cout<<"p.first "<<p.first<<" p.second "<<p.second<<std::endl;
    return 0;
}
