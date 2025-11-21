#pragma once
#ifndef _HUMANA_HPP_
#define _HUMANA_HPP_

#include <string.h>
#include "Weapon.hpp"


class HumanA
{
    private:
        std::string name;
        Weapon& weapon;


    public:
        /* WE CAN'T DO THIS (we can not construct
            a HumanA object without init ref to weapon class)*/
        //! HumanA( void );
        HumanA(std::string name, Weapon& weapon);
        ~HumanA( void );

        void attack();
};

#endif