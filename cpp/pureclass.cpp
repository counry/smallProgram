/*
 * =====================================================================================
 *
 *       Filename:  class.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/01/2016 01:34:05 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */


#include <iostream>


class Uncopyable {
public:
    Uncopyable() 
    {
       init(); 
    }
    virtual void log() const = 0;
    //{
    //    std::cout << "log Uncopyable" << std::endl;
    //}
    ~Uncopyable() {}
private:
    void init()
    {
        log();
    }
};

class buyUncopyable:public Uncopyable {
public:
    virtual void log () const;
};

void buyUncopyable::log() const
{
    std::cout << "log buyUncopyable" << std::endl;
}

int main(void)
{
    buyUncopyable b;
    return 0;
}

