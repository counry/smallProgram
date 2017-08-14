/*
 * =====================================================================================
 *
 *       Filename:  array_begin_end.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/28/2017 12:46:00 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <iterator>

int main(void)
{
	int ia[] = {0, 1, 2, 3, 4, 5};
	int *beg = std::begin(ia);
	int *last = std::end(ia);
	std::cout << "begin:" << *beg  << " end:" << *last << std::endl;
	return 0;

}
