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
    public:
        void swap(MyContainer &X) {
            std::swap(numElems, X.numElems);
        }
        void setNum(int num) {
            numElems = num;
        }
        int getNum() {
            return numElems;
        }
};

inline void swap(MyContainer &c1, MyContainer &c2)
{
    c1.swap(c2);
}

int main(void)
{
    MyContainer c1;
    MyContainer c2;
    c1.setNum(100);
    c2.setNum(200);
    
    cout << "before swap c1 " << c1.getNum() << " c2 " << c2.getNum() << endl;
    
    swap(c1, c2);

    cout << "after swap c1 " << c1.getNum() << " c2 " << c2.getNum() << endl;
    
    string info[3] = {"aaaa"};
    cout << "zzzzzzzzzz" << endl;
    //info[0] = "aaaaaaaaaa";
    //info[1] = "bbbbbbbbbb";
    //info[3] = "cccccccccc";
    cout << info << endl;
    for(int i = 0; i < 3; i++) {
        if (info[i].size() > 0) {
        cout << "info[" << i << "] : " << info[i] << endl;
        }
    }

    return 0;
}
