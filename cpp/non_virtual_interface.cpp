/*
 * =====================================================================================
 *
 *       Filename:  non_virtual_interface.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  04/28/2016 09:24:38 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */


#include <iostream>

class GameCharacter {
public:
    int healthValue() const
    {
        std::cout << "start healthValue..." << std::endl;
        int retVal = doHealthValue();
        std::cout << "end healthvalue..." << std::endl;
    }
private:
    virtual int doHealthValue() const
    {
        std::cout << "GameCharacter doHealthValue " << std::endl;
        return 0;
    }
};

class SubGameCharacter: public GameCharacter {
private:
    virtual int doHealthValue() const
    {
        std::cout << "SubGameCharacter doHealthValue " << std::endl;
        return 0;
    }
};

int main(void)
{
    GameCharacter *gc = new GameCharacter();
    GameCharacter *sgc = new SubGameCharacter();
    gc->healthValue();
    std::cout << "-----------" << std::endl;
    sgc->healthValue();
    return 0;
}

