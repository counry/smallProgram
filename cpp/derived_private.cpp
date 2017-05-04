/*
 * =====================================================================================
 *
 *       Filename:  derived_private.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  05/04/2016 09:13:53 AM
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
    int y;
protected:
    int z;
};


class derived1 : public Base {
public:
    void print_value(void) {
        //std::cout << "x = " << x << std::endl;
        std::cout << "y = " << y << std::endl;
        std::cout << "z = " << z << std::endl;
    }
    void set_value(int _x, int _y, int _z)
    {
        //x = _x;
        y = _y;
        z = _z;
    }
};

class derived2 : protected Base {
public:
    void print_value(void) {
        //std::cout << "x = " << x << std::endl;
        std::cout << "y = " << y << std::endl;
        std::cout << "z = " << z << std::endl;
    }
    void set_value(int _x, int _y, int _z)
    {
        //x = _x;
        y = _y;
        z = _z;
    }
};

class derived3 : private Base {
public:
    void print_value(void) {
        //std::cout << "x = " << x << std::endl;
        std::cout << "y = " << y << std::endl;
        std::cout << "z = " << z << std::endl;
    }
    void set_value(int _x, int _y, int _z)
    {
        //x = _x;
        y = _y;
        z = _z;
    }
};

void study(const Base &s)
{
    std::cout << "study" << std::endl;
}

int main(void)
{
    derived1 d1;
    derived2 d2;
    derived3 d3;
    study(d1);
    study(d2);
    study(d3);
    return 0;
}

