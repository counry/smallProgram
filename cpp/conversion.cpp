/*
 * =====================================================================================
 *
 *       Filename:  conversion.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/29/2014 05:01:59 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */


#include <iostream>



int main(void)
{
    //小圆括号转换类型可以替代除dynamic_cast之外的其他类型转换

    //static_cast : 语言内建规则转换
    float x = 1.1;
    //print x as int
    std::cout<<"static_cast<int>(x) "<< static_cast<int>(x) << std::endl;
    std::cout<<"<int>(x) "<< (int)x << std::endl;

    //dynamic_cast : 将多态类型向下转型为其实际静态类型，唯一在执行期进行检验的转型动作
    class Car {
    public:
        virtual void fun(void) {std::cout<<"Car"<<std::endl;}
    };
    class Cabriolet : public Car {
        
        void fun(void) {std::cout<<"Cabriolet"<<std::endl;}
    };
    class Limousine : public Car {
        void fun(void) {std::cout<<"Limousine"<<std::endl;}
    };
    Cabriolet *cb = new Cabriolet();
    Car *ca = dynamic_cast<Cabriolet *>(cb);
    Car *ca1 = cb;
    ca->fun();
    ca1->fun();

    //const_cast : 设定或者去除类型的常数型
 
    

    return 0;
}

