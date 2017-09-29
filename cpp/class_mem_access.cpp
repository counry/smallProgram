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



class Quote {
public:
    Quote(){}

    virtual void net_price(){
        std::cout << "in quote net_price" << std::endl;
    }
};

class Bulk_quote : public Quote {
public:
    Bulk_quote(){}
    using Quote::net_price;
    void net_price(int i) {
        std::cout << "in Bulk_quote net_price" << std::endl;
    }

};


int main(void)
{
    Bulk_quote d;
    Quote b;
    b.net_price();
    d.net_price(10);
    d.net_price();
    //d.Quote::net_price();
    return 0;
}
