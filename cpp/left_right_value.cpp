/*
 * =====================================================================================
 *
 *       Filename:  left_right_value.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/10/2014 10:30:52 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */


#include <iostream>
#include <algorithm>
#include <map>


class Test {
public:
    int a;
    int b;
};

Test add(Test ta, Test tb)
{
    Test tmp;
    tmp.a = ta.a + tb.a;
    tmp.b = ta.b + tb.b;
    return tmp;
}

std::map<uint64_t, Test> g_map;

int test(void)
{
    for(int i = 0; i < 10; i++) {
        Test t1;
        t1.a = 10+i;
        t1.b = 20+i;
        Test t2;
        t2.a = 30+i;
        t2.b = 40+i;

        const auto lvalue = add(t1, t2);
        const auto &rvalue = add(t1, t2);

        if (g_map.find(i) == g_map.end()) {
            g_map.insert({i, rvalue});
        }

        std::cout << "lvalue.a=" << lvalue.a << "lvalue.b=" << lvalue.b << std::endl;
        std::cout << "rvalue.a=" << rvalue.a << "rvalue.b=" << rvalue.b << std::endl;
    }
    return 0;
}

void print_map()
{
    for (auto &m : g_map) {
        std::cout << "[" << m.first << "]=[a=" << m.second.a << " b=" << m.second.b << "]" << std::endl;
    }
}

int main(void)
{
    test();
    print_map();
    return 0;
}
