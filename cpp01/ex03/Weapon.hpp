#pragma once
#ifndef _WEAPON_HPP_
#define _WEAPON_HPP_

#include <string>

class Weapon
{
    private:
        std::string type;

    public:
        Weapon( void );
        Weapon(std::string name);
        ~Weapon( void );

        void setType(std::string type);
        const std::string &getType(void) const ;
};

#endif