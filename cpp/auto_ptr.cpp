/*
 * =====================================================================================
 *
 *       Filename:  auto_ptr.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/30/2014 02:04:07 PM
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
#include <unistd.h>

int g_size = 0;

class ClassA {
    public:
        int m_memory[10*1024*1024];
    ~ClassA() {std::cout<<"delete ClassA"<<std::endl;}
};

//auto_ptr 是指向对象拥有者，当auto_ptr摧毁时，对象也会摧毁
//auto_ptr要求只能有一个拥有者，严禁一物二主
int main(void)
{
    while(1) {
        std::auto_ptr<ClassA> ptr(new ClassA); //如果为const只是不能更改auto_ptr的拥有权，但所拥有的对象可以更改
        const std::auto_ptr<ClassA> ptr2(ptr); //拥有权转移
        if (ptr.get() == NULL) { //判断智能指针为空的方法
            std::cout << "ptr is null" << std::endl;
        }
        if (ptr2.get() == NULL) {
            std::cout << "ptr2 is null" << std::endl;
        }
        ptr2->m_memory[0] = 100;
        g_size += sizeof(ClassA);
        std::cout<<"g_size "<<g_size<<std::endl;
        break;
        
    }
    return 0;
}
