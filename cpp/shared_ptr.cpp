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

class share_ptr_test {
public:
    share_ptr_test(int m):m_memory(m) {}
    int m_memory;
    ~share_ptr_test() {std::cout<<"delete share_ptr_test"<<std::endl;}
};

int main(void)
{
    std::shared_ptr<share_ptr_test> ptr1(new share_ptr_test(10));
    auto ptr2 = std::make_shared<share_ptr_test>(11);
    auto ptr5(new share_ptr_test(15));
    //std::shared_ptr<share_ptr_test> ptr6 = new share_ptr_test(15);

    std::cout << ptr2.get()->m_memory << std::endl;
    std::shared_ptr<share_ptr_test> ptr3(ptr1);
    {
        auto ptr4(ptr1);
        std::cout << "ptr4.use_count()=" << ptr4.use_count() << std::endl;

    }

    std::cout << "ptr1.use_count()=" << ptr1.use_count() << std::endl;
    std::cout << "ptr2.use_count()=" << ptr2.use_count() << std::endl;
    std::cout << "ptr3.use_count()=" << ptr3.use_count() << std::endl;
    ptr3 = std::make_shared<share_ptr_test>(12);
    auto ptr4 = new auto(*ptr3);
    return 0;
}
