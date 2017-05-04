/*
 * =====================================================================================
 *
 *       Filename:  stream_iter.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/10/2014 02:51:34 PM
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
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

int main(void)
{
    vector<int> coll;

    copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(coll));

    sort(coll.begin(), coll.end());

    unique_copy(coll.begin(), coll.end(), ostream_iterator<int>(cout, "\n"));

}
