/*
 * =====================================================================================
 *
 *       Filename:  shared_ptr.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/06/2016 09:27:55 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <memory>
#include <boost/shared_ptr.hpp>

class ClassA {
public:
    int m_memory[10*1024*1024];
    ~ClassA() {std::cout<<"delete ClassA"<<std::endl;}
};

int main(void)
{
    boost::shared_ptr<ClassA> ptr1(new ClassA);
    boost::shared_ptr<ClassA> ptr2(ptr1);
    return 0;   
}
