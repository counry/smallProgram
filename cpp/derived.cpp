/*
 * =====================================================================================
 *
 *       Filename:  derived.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/26/2016 09:17:19 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>

class Base {
private:
    int x;
public:
    virtual void mf1() = 0;
    virtual void mf1(int) {std::cout << "Base:virtual void mf1(int)" << std::endl;}
    virtual void mf2() {std::cout << "Base:virtual void mf2()" << std::endl;}
    void mf3() {std::cout << "Base:void mf3()" << std::endl;};
    void mf3(double) {std::cout << "Base:void mf3(double)" << std::endl;};
};                                   

class Derived:public Base {          
public:                              
    virtual void mf1() {std::cout << "Derived:virtual void mf1()" << std::endl;}
    void mf3() {std::cout << "Derived:void mf3()" << std::endl;}
    void mf4() {std::cout << "Derived:void mf4()" << std::endl;}
};

int main(void)
{
    Derived d;
    int x;
    d.mf1();
    d.mf1(x);
    d.mf2();
    d.mf3();
    d.mf3(x);

    return 0;
}
