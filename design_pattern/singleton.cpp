/*
 * =====================================================================================
 *
 *       Filename:  singleton.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/05/2017 02:25:13 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */


#include <iostream>



class op_database {
public:
    static op_database& get_op_database(void)
    {
        static op_database database;
        return database;
    }

friend class operation;
private:
    op_database(void):m_number(11) {

    }

    int m_number;

};

class operation {
public:
    operation():test1(10) {}

    static void init() {
        op_database::get_op_database();
    }

    static int get_m_number() {
        return op_database::get_op_database().m_number;
    }

public:
    int test1;
    int test2;
};

namespace op {
#define CONF "./config_test"
}


void test_string(std::string str) {
    std::cout << "str=" << str << std::endl;
}



int main(void)
{
    operation oper;
    std::cout << oper.test1 << oper.test2 << std::endl;
    std::cout << "number=" << operation::get_m_number() << std::endl;
    test_string(CONF);
}

