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

//https://blog.smartbear.com/development/the-biggest-changes-in-c11-and-why-you-should-care/

#include <iostream>
#include <memory>
#include <string>
#include <map>
#include <vector>

class share_ptr_test {
public:
    share_ptr_test(int m):m_memory(m) {}
    int m_memory;
    ~share_ptr_test() {std::cout<<"delete share_ptr_test"<<std::endl;}
};

class X {
public:
    int a[4];
public:
    X() : a{1,2,3,4} {} //C++11, member array initializer
};

class C
{
public:
    int a=7; //C++11 only
public:
    C(){};
};

int main(void)
{
    share_ptr_test sp1(101);
    share_ptr_test sp2 = share_ptr_test(102);
    share_ptr_test sp3 = 103;
    share_ptr_test sp4 = {104};
    share_ptr_test sp5 {105};
    share_ptr_test sp6[3] = {106, 107, 108};
    int *pint = new int [3] {109, 110, 111};
    typedef int arrT[3];
    int *pint2 = new arrT {112,113,114};
    //share_ptr_test *sp7 = new share_ptr_test [3] {share_ptr_test(109), share_ptr_test(110), share_ptr_test(111)};
    std::cout << "sp1.m_memory = " << sp1.m_memory << std::endl;
    std::cout << "sp2.m_memory = " << sp2.m_memory << std::endl;
    std::cout << "sp3.m_memory = " << sp3.m_memory << std::endl;
    std::cout << "sp4.m_memory = " << sp4.m_memory << std::endl;
    std::cout << "sp5.m_memory = " << sp5.m_memory << std::endl;
    std::cout << "sp6.m_memory = " << sp6[0].m_memory << " " << sp6[1].m_memory << " " << sp6[2].m_memory << std::endl;
    //std::cout << "sp7.m_memory = " << sp7[0]->m_memory << " " << sp7[1]->m_memory << " " << sp7[2]->m_memory << std::endl;
    std::cout << "pint = " << pint[0] << " " << pint[1] << " " << pint[2] << std::endl;
    std::cout << "pint2 = " << pint2[0] << " " << pint2[1] << " " << pint2[2] << std::endl;
    delete [] pint;
    delete [] pint2;  //虽然pint2是使用的arrT申请的内存，但是释放不能使用delete pint2，必须加[]

    // C++11 container initializer
    std::vector<std::string> vs = {"first", "second", "third"};
    std::vector<int> vi = {7, 8, 9};
    std::map<std::string, std::string> singers = {{"Lady Gaga", "+1 (212) 555-7890"},
                                                  {"Beyonce Knowles", "+1 (212) 555-0987"}};

    X x;
    C c;
    std::cout << "x.a=" << x.a[0] << " " << x.a[1] << " " << x.a[1] << " " << x.a[1] << std::endl;
    std::cout << "c.a=" << c.a<< std::endl;

    return 0;
}
