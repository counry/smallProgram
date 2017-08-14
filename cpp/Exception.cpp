/*
 * =====================================================================================
 *
 *       Filename:  exception.cpp
 *
 *    Description:
 *
 *        Version:  1.0
 *        Created:  09/30/2014 11:01:18 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (),
 *        Company:
 *
 * =====================================================================================
 */


#include <iostream>
#include <exception>

class MyProblem : public std::exception {
public:
    virtual const char* what() const throw() {
        return "this is a test for exception";
    }
};

void f() throw(MyProblem)
{
    throw MyProblem();
}

int main(void)
{
    try {
        f();
    } catch (const std::exception &error) {
        std::cout<<error.what()<<std::endl;
    } catch(...) {
        std::cout << "here 22222" << std::endl;
    }

    return 0;
}

