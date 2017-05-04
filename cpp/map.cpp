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

#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(void)
{
    typedef map<string, float> StringFloatMap;

    StringFloatMap stocks;

    stocks["BASF"] = 369.50;
    stocks["VW"] = 413.50;
    stocks["BMW"] = 819.50;
    stocks["NS"] = 842.50;
    stocks.insert(StringFloatMap::value_type("otto", 222.2));
    stocks.insert(pair<string, float>("otto1", 333.3));
    stocks.insert(make_pair("otto2", 444.4));

    StringFloatMap::iterator pos;
    for (pos = stocks.begin(); pos != stocks.end(); ++pos) {
        cout << "stock: " << pos->first << "\t"
             << "price: " << pos->second << endl;
    }
    cout << endl;

    for (pos = stocks.begin(); pos != stocks.end(); ++pos) {
        pos->second *= 2;    
    }

    for (pos = stocks.begin(); pos != stocks.end(); ++pos) {
        cout << "stock: " << pos->first << "\t"
             << "price: " << pos->second << endl;
    }
    cout << endl;

    stocks["Volkswagen"] = stocks["VW"];
    stocks.erase("VW");

    for (pos = stocks.begin(); pos != stocks.end(); ++pos) {
        cout << "stock: " << pos->first << "\t"
             << "price: " << pos->second << endl;
    }
    float a =  stocks["AAA"];
    cout << "a " << a << endl;
    

    return 0;
}


