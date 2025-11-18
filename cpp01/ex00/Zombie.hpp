#pragma once
#ifndef __ZOMBIE_HPP__
#define __ZOMBIE_HPP__


#include <iostream>
#include <string>

class Zombie
{
    private:
        std::string name;

    public:
        /* Constructor */
        Zombie(std::string name);

        void announce( void ); // <name>: BraiiiiiiinnnzzzZ...

        /* Destructor */
        ~Zombie(void);
};

void randomChump( std::string name );
Zombie* newZombie( std::string name );

#endif

