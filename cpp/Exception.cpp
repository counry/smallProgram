
/*
 * =====================================================================================
 *
 *       Filename:  Exception.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/05/2016 02:03:54 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <stdexcept>

int main(void)
{
    try {
        std::cout << "start ..." << std::endl;
        int i = 52%0;
        std::cout << "i = " << i << std::endl;
    } catch(std::exception& e) {
        std::cout << "here 11111" << std::endl;
        std::cout<<e.what()<<std::endl;
    } catch(...) {
        std::cout << "here 22222" << std::endl;
    }
    std::cout << "aaaa" << std::endl;

    return 0;
}
