/*
 * =====================================================================================
 *
 *       Filename:  const_function.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/18/2016 07:18:52 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <iostream>

class TextBlock {
public:
    TextBlock(std::string txt)
    {
        text = txt;
    }

    const char& operator[] (std::size_t position) const
    {
        return text[position];
    }       

private:
    std::string text;
};


int main(void)
{
    TextBlock tb("Hello");
    std::cout << tb[0];
    tb[0] = 'C';
    return 0;
}
