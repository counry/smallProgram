/*
 * =====================================================================================
 *
 *       Filename:  explicit.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/29/2014 04:54:49 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */


#include <iostream>

class Stack {
public:
    Stack(){}
    //explicit Stack(int size){ 
    Stack(int size){ 
        m_size = size;
    }

    int m_size;
};

const Stack operator*(const Stack &lhs, const Stack &rhs)
{
    return Stack(lhs.m_size*rhs.m_size);
}

int main(void)
{
    Stack s;
    s = 40;
    Stack ret = 2 * s;
    std::cout<<"Stack size "<<s.m_size<<std::endl;
    std::cout<<"Stack size "<<ret.m_size<<std::endl;
 
    return 0;
}
