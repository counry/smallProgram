/*
 * =====================================================================================
 *
 *       Filename:  swap.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/10/2014 10:30:52 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */


#include <iostream>
#include <algorithm>

using namespace std;

class MyContainer {
    private:
        int numElems;
        float fnumElems;
    public:
        void swap(MyContainer &X) {
            std::swap(numElems, X.numElems);
            std::swap(fnumElems, X.fnumElems);
        }

        void setNum(int num) {
            numElems = num;
        }

        int getNum() {
            return numElems;
        }

        void setFNum(float num) {
            fnumElems = num;
        }

        float getFNum() {
            return fnumElems;
        }

        bool operator== (const MyContainer &x) const {
            return (numElems==x.numElems && fnumElems==x.fnumElems);
        }

        bool operator< (const MyContainer &x) const {
            return (numElems<x.numElems && fnumElems<x.fnumElems);    
        }
};


int main(void)
{
 
    using namespace std::rel_ops;
    MyContainer c1;
    MyContainer c2;
    c1.setNum(100);
    c1.setFNum(10.10);
    c2.setNum(200);
    c2.setFNum(20.20);
    
    cout << " c1 num " << c1.getNum() << " fnum " << c1.getFNum() << " c2 num " << c2.getNum() << " fnum " << c2.getFNum() << endl;
    
    if(c1 != c2) {
        cout << "c1 != c2" << endl;
    }

    if (c1 > c2) {
        cout << "c1 > c2" << endl;
    }

    if (c1 <= c2) {
        cout << "c1 <= c2" << endl;
    }

    if (c1 >= c2) {
        cout << "c1 >= c2" << endl;
    }

    return 0;
}
