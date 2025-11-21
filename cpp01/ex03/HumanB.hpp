#pragma once
#ifndef _HUMANB_HPP_
#define _HUMANB_HPP_

#include <string.h>
#include "Weapon.hpp"

class HumanB
{
    private:
        std::string name;
        Weapon *weaponPtr;
    public:
        HumanB( void );
        HumanB (std::string name);
        ~HumanB( void );

        void setWeapon(Weapon &weapon);
        void attack( void );

};

#endif