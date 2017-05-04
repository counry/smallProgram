/*
 * =====================================================================================
 *
 *       Filename:  vector.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/11/2014 11:02:25 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <deque>

using namespace std;

int main(void)
{
    vector<int> col(10);
    
    cout << "init col(10):" << endl;
    cout << "size: " << col.size() << endl;
    cout << "max_size: " << col.max_size() << endl;
    cout << "capacity: " << col.capacity() << endl;
    cout << endl;

    for (int i = 1; i < 10; i++) {
        col.push_back(i);
    }

    cout << "push_back 9:" << endl;
    cout << "size: " << col.size() << endl;
    cout << "max_size: " << col.max_size() << endl;
    cout << "capacity: " << col.capacity() << endl;
    cout << endl;

    for (int i = 1; i < 10; i++) {
        col.push_back(i);
    }

    cout << "push_back 9:" << endl;
    cout << "size: " << col.size() << endl;
    cout << "max_size: " << col.max_size() << endl;
    cout << "capacity: " << col.capacity() << endl;
    cout << endl;

    col.resize(5);   
    cout << "resize(5):" << endl;
    cout << "size: " << col.size() << endl;
    cout << "max_size: " << col.max_size() << endl;
    cout << "capacity: " << col.capacity() << endl;
    cout << endl;

    col.clear();
    cout << "clear:" << endl;
    cout << "size: " << col.size() << endl;
    cout << "max_size: " << col.max_size() << endl;
    cout << "capacity: " << col.capacity() << endl;
    cout << endl;

    col.reserve(100);
    cout << "reserve(100):" << endl;
    cout << "size: " << col.size() << endl;
    cout << "max_size: " << col.max_size() << endl;
    cout << "capacity: " << col.capacity() << endl;
    cout << endl;

    typedef vector<int>::iterator vecitr;
    vecitr itr = col.begin();
    vecitr itr_end = col.end();
    col.erase(itr, itr_end);
    cout << "erase:" << endl;
    cout << "size: " << col.size() << endl;
    cout << "max_size: " << col.max_size() << endl;
    cout << "capacity: " << col.capacity() << endl;
    cout << endl;

    vector<int> col1(10);
    col.swap(col1);
    cout << "swap(col1(10)):" << endl;
    cout << "size: " << col.size() << endl;
    cout << "max_size: " << col.max_size() << endl;
    cout << "capacity: " << col.capacity() << endl;
    cout << endl;

    return 0;
}

