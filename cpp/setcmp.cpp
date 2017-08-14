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
#include <sstream>

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

class range {
public:
    range(long start, long end, int seq):m_start(start),m_end(end),m_seq(seq){}
    std::string get_range_str() const
    {
        std::stringstream oss;
        oss.str("");
        oss << "range("<<m_start<<","<<m_end<<"): seq(" << m_seq<<")";
        return std::string(oss.str());
    }
    long m_start;
    long m_end;
    int m_seq;

};

bool compare(const range& lhs, const range& rhs)
{
    return lhs.m_end < rhs.m_end;
}

int main(void)
{
    range r1(10,50,1);
    range r2(51,60,2);
    range r3(61,70,3);
    range r4(71,80,4);
    range r5(81,90,5);
    range r(73,73,0);
    std::set<range, decltype(compare)*> iset(compare);
    iset = {r1,r2,r3,r4,r5};
    auto ret = iset.find(r);
    if (ret != iset.end()) {
        std::cout << "find:" << ret->get_range_str() << std::endl;
    }
    ret = iset.lower_bound(r);
    if (ret != iset.end()) {
        std::cout << "lower_bound:" << ret->get_range_str() << std::endl;
    }
    ret = iset.upper_bound(r);
    if (ret != iset.end()) {
        std::cout << "upper_bound:" << ret->get_range_str() << std::endl;
    }
    return 0;
}



