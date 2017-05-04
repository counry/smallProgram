/*
 * =====================================================================================
 *
 *       Filename:  class.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/01/2016 01:34:05 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */


#include <iostream>


template<class T>
class NameObject {
public:
    NameObject(std::string &name, const T &value):nameValue(name),objectValue(value)
    { 
    }
private:
    std::string &nameValue;
    const T objectValue;
};

class Uncopyable {
protected:
    Uncopyable() {}
    ~Uncopyable() {}
private:
    Uncopyable(const Uncopyable &);
    Uncopyable & operator=(const Uncopyable &);
};

int main(void)
{
    std::string newDog("Persephone");
    std::string oldDog("Satch");

    NameObject<int> p(newDog, 2);
    NameObject<int> s(oldDog, 36);

    /*reference and const variable can not call copy assignment operator function*/
    //p = s;

    /*拷贝构造和相等运算函数为私有函数，阻止生成对象*/
    Uncopyable uc;
    Uncopyable uc2(uc);

    return 0;
}

