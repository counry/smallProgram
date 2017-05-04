/*
 * =====================================================================================
 *
 *       Filename:  swap.cpp
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
#include <sstream>
#include <string.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

int main(void)
{
    stringstream ss;
    ss.clear();
    ss << "123456789";
    cout << ss.str() << "has char : " << ss.str().length() <<  std::endl;
    ss << "123456789";
    cout << ss.str() << "has char : " << ss.str().size() <<  std::endl;
    char a[10] = "100000";
    ss.str("");
    ss<<a<<std::endl;
    cout << ss.str() << std::endl;

    char* p = (char *)malloc(10+5);
    memset(p, 0x00, 15);
    memcpy(p+11, "ABCD", 4);
    memcpy(p, "12345678901", 11);
    std::string test = p;
    std::cout << "test : " << test << std::endl;
    std::cout << "p : " << p << "sizeof(p):" << sizeof(p) << " strlen " << strlen(p) << std::endl;
    std::ofstream file;
    file.open("a.test", std::ios::out|std::ios::trunc);
    if (file.is_open()) {
        file << p;
        file.close();
    }
    string aaa(p, 13);
    std::cout << "aaa : " << aaa << std::endl;
    ss.str("");
    ss.write(p, 13);
    std::cout << "ss : " << ss.str() << std::endl;
    
    string str_t = "1234567890abc";
    std::cout << str_t << std::endl;
    std::cout << str_t.substr(0, str_t.find_last_of("\r\n")) << std::endl;
    str_t.clear();
    std::cout << str_t.substr(0, str_t.size()) << std::endl;
    return 0;
}

