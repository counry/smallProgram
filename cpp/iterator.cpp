/*
 * =====================================================================================
 *
 *       Filename:  iterator.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/10/2014 11:41:10 AM
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
#include <iterator>
#include <algorithm>

using namespace std;

void print(char elem)
{
    cout << elem << "-";
}

int main(void)
{
    list<char> coll;

    for (char c='a'; c<='z'; ++c) {
        coll.push_back(c);
    }

    list<char>::const_iterator pos;
    for (pos = coll.begin(); pos != coll.end(); ++pos) {
        cout << *pos << " ";
    }
    cout << endl;

    copy(coll.rbegin(), coll.rend(), ostream_iterator<char>(cout, " "));
    cout << endl;
  
    coll.erase(remove(coll.begin(), coll.end(), 'a'), coll.end());
    copy(coll.begin(), coll.end(), ostream_iterator<char>(cout, " "));
    cout << endl;
  
    for_each(coll.begin(), coll.end(), print);
    cout << endl;

    return 0;
}
