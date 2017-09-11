/*
 * =====================================================================================
 *
 *       Filename:  process_resource.cpp
 *
 *    Description:  :
 *
 *
 *        Version:  1.0
 *        Created:  09/11/2017 11:54:09 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <sys/resource.h>

int main(void)
{
	struct rusage res;
	if (getrusage(RUSAGE_SELF, &res) == 0) {
		
	} else {
		std::cout << "getrusage error" << std::endl;
	}
	return 0;
}
