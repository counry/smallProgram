/*
 * =====================================================================================
 *
 *       Filename:  const_static_member.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/30/2014 10:04:12 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */


#include <iostream>


class MyClass {
public:
    static const int num;
public:
    int elem;

};

const int MyClass::num = 300;

int main(void)
{
    MyClass mc;
    mc.elem = 200;
    std::cout<<"num = "<<MyClass::num<<" elem "<<mc.elem<<std::endl;
    return 0;
}
