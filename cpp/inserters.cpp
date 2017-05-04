/*
 * =====================================================================================
 *
 *       Filename:  inserters.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/10/2014 02:14:03 PM
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
#include <list>
#include <deque>
#include <set>
#include <algorithm>

using namespace std;

int main(void)
{
    list<int> coll1;

    for (int i=1; i<=9; ++i) {
        coll1.push_back(i);
    }
   
    vector<int> coll2;
    typedef vector<int>::iterator vectoritr;
    copy(coll1.begin(), coll1.end(), back_inserter(coll2));
    cout << "vector<int> back_inserter coll2: ";
    for (int i=0; i<coll2.size(); ++i) {
        cout << coll2[i] << " ";
    }
    cout << endl;


    deque<int> coll3;
    typedef deque<int>::iterator dequeitr;
    copy(coll1.begin(), coll1.end(), front_inserter(coll3));
    cout << "deque<int> front_inserter coll3: ";
    for (int i=0; i<coll3.size(); ++i) {
        cout << coll3[i] << " ";
    }
    cout << endl;


    set<int> coll4;
    typedef set<int>::iterator setitr;
    setitr pos;
    copy(coll1.begin(), coll1.end(), inserter(coll4, coll4.begin()));
    cout << "set<int> inserter coll4: ";
    for (pos = coll4.begin(); pos != coll4.end(); ++pos) {
        cout << *pos << " ";
    }
    cout << endl;
 
    cout << "list<int> coll1: ";
    while(!coll1.empty()) {
        cout << coll1.front() << " ";
        coll1.pop_front();
    }
    cout << endl;
 

    return 0;
}
