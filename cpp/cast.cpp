/*
 * =====================================================================================
 *
 *       Filename:  cast.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/13/2016 09:34:40 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>

class Window {
public:
    virtual void onResize() 
    {
        m_win = "modify in window";
    }

    std::string m_win;
};


class SpecialWindow:public Window {
public:
    virtual void onResize()
    {
        static_cast<Window>(*this).onResize();
        //Window::onResize();
        m_spc_win = "modify in  SpecialWindow";
    }

    std::string m_spc_win;
};

int main(void)
{
    SpecialWindow sw;
    sw.onResize();
    std::cout << "sw.m_win: " << sw.m_win << " sw.m_spc_win: " << sw.m_spc_win << std::endl;
    return 0;
}
