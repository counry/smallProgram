/*
 * =====================================================================================
 *
 *       Filename:  member_template.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/29/2014 03:47:36 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */


#include <iostream>

template <class T>
class MyClass {
    private:
        T value;
    public:
        template <class U>
        MyClass (const MyClass<U> &x) {
            value = x.getValue();
        }
        MyClass() {}
        template <class X>
        void assign(const MyClass<X> &x) {
            value = x.getValue();
        }
        void setValue(T va) {
            value = va;
        }
        T getValue() const {
            return value;
        }
};

void f(void)
{
    MyClass<int> i;
    MyClass<double> d;
    MyClass<double> dd;

    dd.setValue(2.2);
    d.setValue(1.1);
    i.setValue(5);

    d.assign(dd);
    d.assign(i);
    MyClass<int> ii(i);
    MyClass<int> iii(d);
    std::cout<<"d.value "<<i.getValue()<<" "<<ii.getValue()<<" "<<iii.getValue()<<" "<<d.getValue()<<" "<<dd.getValue()<<std::endl;
}

int main(void)
{
    f();
    return 0;
}
