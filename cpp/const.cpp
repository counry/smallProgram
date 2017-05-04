/*
 * =====================================================================================
 *
 *       Filename:  const.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/31/2016 06:18:18 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>

struct Point {
    int x;
    int y;
};

class ABEntry {
    public:
        const int m_iabentry;
        std::string m_str;
        int m_i2;
        int &m_iabentry_ref;
        Point po;
        ABEntry():m_iabentry(1),m_iabentry_ref(m_i2)
        {
            m_str = "test";
            po.x = 10;
            po.y = 20;
        }

        const Point &left() const {return po;}
        const Point lower() const {return po;}
};

int main(void)
{
    ABEntry abe;
    std::cout << "ABEntry m_iabentry : " << abe.m_iabentry << std::endl;
    std::cout << "ori x=" << abe.po.x << " y=" << abe.po.y << std::endl;
    Point &p1 = abe.left();
    Point &p2 = abe.lower();
    p1.x = 30;
    p2.x = 40;
    std::cout << "ori2 x=" << abe.po.x << " y=" << abe.po.y << std::endl;
    std::cout << "p1 x=" << p1.x << " y=" << p1.y << std::endl;
    std::cout << "p2 x=" << p2.x << " y=" << p2.y << std::endl;
    p2 = p1;
    p1 = p2;
    return 0;
}
