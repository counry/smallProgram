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
#include <list>
#include <algorithm>

class AddValue {
    private:
        int theValue;
    public:
        AddValue(int v) : theValue(v) {}

        void operator() (int &elem) const {
            elem += theValue;
        }
};


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
    std::list<int> coll1;

    for (int i=1; i<=9; i++) {
        coll1.push_back(i);
    }
    PRINT_ELEM(coll1, "initialized: ");

    for_each(coll1.begin(), coll1.end(), AddValue(10));
    PRINT_ELEM(coll1, "after add: ");  

}
