/*
 * =====================================================================================
 *
 *       Filename:  dynamic_bind.cpp
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

//final 标示类不可继承
class NoQuote final {
public:
    NoQuote(int size):m_size(size){}

    virtual void net_price(){
        std::cout << "in quote net_price" << std::endl;
    }

    int m_size;
};

class Quote {
public:
    Quote(int size):m_size(size){}

    virtual void net_price(){
        std::cout << "in quote net_price" << std::endl;
    }

    //不可覆盖
    virtual  int final_test() final {
        std::cout << "no override" << std::endl;
    }

    int m_size;
};

class Bulk_quote : public Quote {
public:
    Bulk_quote(int size):Quote(size){}

    //标示覆盖基类虚函数
    void net_price() override {
        Quote::net_price();
        std::cout << "in Bulk_quote net_price" << std::endl;
    }

//    int final_test() {
//        std::cout << "ok override" << std::endl;
//    }
};

class Bulk_quote_pure : public Bulk_quote {
public:
    Bulk_quote_pure(int size):Bulk_quote(size){}
    virtual void test_pure() = 0;
};

void Bulk_quote_pure::test_pure() {
    std::cout << "Bulk_quote_pure::test_pure" << std::endl;
}

class Bulk_quote_pure_instance : public Bulk_quote_pure {
public:
    Bulk_quote_pure_instance(int size):Bulk_quote_pure(size){}
    void test_pure() {
        std::cout << "Bulk_quote_pure_instance::test_pure" << std::endl;
        Bulk_quote_pure::test_pure();
    }
};

void print_total(Quote& item)
{
    item.net_price();
    //调用指定版本的函数
    //item.Quote::net_price();
}

int main(void)
{
    Quote q(10);
    Bulk_quote b(11);
    print_total(q);
    print_total(b);
    Bulk_quote_pure_instance bpi(1);
    bpi.test_pure();
    return 0;
}
