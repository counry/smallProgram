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
#include <vector>
#include <stdlib.h>

class share_ptr_test {
public:
    share_ptr_test(int m):m_memory(m) {}
    virtual void f() {std::cout << "in base share_ptr_test" << std::endl;}
    int m_memory;
    ~share_ptr_test() {std::cout<<"delete share_ptr_test"<<std::endl;}
};

struct derived_share_ptr_test : share_ptr_test
{
public:
    derived_share_ptr_test(int m):share_ptr_test(m){}

    void f()
    {
        std::cout << "in derived derived_share_ptr_test" << std::endl;
    }
    ~derived_share_ptr_test(){ // note, it's not virtual
        std::cout << "~derived_share_ptr_test " << m_memory << std::endl;
    }
};

derived_share_ptr_test* get_derived_share_ptr_test(void)
{
    return new derived_share_ptr_test(1000);
}

void test_shared_ptr_change()
{
    {
        std::vector<std::shared_ptr<share_ptr_test>> ptr_vec;
        ptr_vec.push_back(std::make_shared<derived_share_ptr_test>(88));
        ptr_vec.push_back(std::make_shared<share_ptr_test>(99));
        int i = 1;
        for (auto &p : ptr_vec) {
            if (i == 1) {
                std::dynamic_pointer_cast<derived_share_ptr_test>(p)->f();
                i++;
            }
            p->f();
            std::cout << "memory=" << p->m_memory << std::endl;
        }
    }
    std::cout << "start ---" << std::endl;
    {
        std::shared_ptr<share_ptr_test> p = std::shared_ptr<share_ptr_test>(get_derived_share_ptr_test());
    }
    std::cout << "end ---" << std::endl;

}


int main(void)
{
    std::shared_ptr<share_ptr_test> ptr_nul = nullptr;
    if (!ptr_nul) {
        std::cout << "ptr_nul is null" << std::endl;
    }
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
    test_shared_ptr_change();
    void *pp_nullptr = nullptr;
    void *pp_null = NULL;
    std::cout << "finish1" << std::endl;
    delete pp_nullptr;
    std::cout << "finish2" << std::endl;
    delete pp_nullptr;
    std::cout << "finish3" << std::endl;
    delete pp_null;
    std::cout << "finish4" << std::endl;
    delete pp_null;
    std::cout << "finish5" << std::endl;
    void *p_free = (void *)malloc(100);
    free(p_free);
    std::cout << "finish6" << std::endl;
    p_free = NULL;
    free(p_free);
    std::cout << "finish7" << std::endl;
    return 0;
}
