/*
 * =====================================================================================
 *
 *       Filename:  function.cpp
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
#include <map>
#include <functional>

int add(int i, int j)
{
    return i + j;
}

class divide {
    int operator()(int denominator, int divisor)
    {
        return denominator / divisor;
    }
};


int main(void)
{
    auto mod = [](int i, int j)
    {
        return i % j;
    };
    std::function<int(int,int)> fadd = add;
    std::cout << fadd(10,5);

    typedef std::function<int(int,int)> Callback;

    std::map<std::string, Callback> binops = {
            {"+", add},
            {"-", std::minus<int>()},
            {"/", divide()},
            {"*", [](int i, int j){return i * j;}},
            {"%", mod}
    };

    int arg1 = 10;
    int arg2 = 5;
    for (auto& b : binops) {
        std::cout << arg1 << b.first << arg2 << "=" << b.second(arg1, arg2) << std::endl;
    }

    return 0;
}
