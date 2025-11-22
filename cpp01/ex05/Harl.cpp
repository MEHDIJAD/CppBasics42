#include "Harl.hpp"
#include <iostream>

void harl::debug( void ){
    std::cout 
    << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
    << std::endl;
}

void harl::info( void ){
    std::cout 
    << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
    << std::endl;
}
void harl::warning( void )
{
    std::cout 
    << "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month."
    << std::endl;
}

void harl::error( void ){
    std::cout 
    << "This is unacceptable! I want to speak to the manager now."
    << std::endl;
}



void harl::complain(std::string level)
{
    cp complain[] = {
        {"DEBUG", &harl::debug},
        {"INFO", &harl::info},
        {"WARNING", &harl::warning},
        {"ERROR", &harl::error}
    };

    for(int i = 0; i < 4; ++i)
    {
        if(complain[i].level == level){
            (this->*(complain[i].action))();
            return ;
        }
    }
}

