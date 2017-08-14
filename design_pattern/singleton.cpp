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
    static void init() {
        op_database::get_op_database();
    }

    static int get_m_number() {
        return op_database::get_op_database().m_number;
    }
};

int main(void)
{
    std::cout << "number=" << operation::get_m_number() << std::endl;
}

