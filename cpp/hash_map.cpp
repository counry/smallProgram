/*
 * =====================================================================================
 *
 *       Filename:  map.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/21/2014 07:42:40 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

//#include <hash_map>
#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    typedef unordered_map<string, float> StringFloatHashMap;

    StringFloatHashMap stocks;

    stocks.insert(make_pair("otto2", 444.4));
    stocks.insert(make_pair("otto2", 555.5));
    stocks.insert(make_pair("otto3", 666.6));

    StringFloatHashMap::iterator pos;
    for (pos = stocks.begin(); pos != stocks.end(); ++pos) {
        cout << "stock: " << pos->first << "\t"
             << "price: " << pos->second << endl;
    }
    cout << endl;

    return 0;
}


