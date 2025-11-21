#pragma once
#ifndef _HARL_HPP_
#define _HARL_HPP_

#include <string>

class harl
{
    private:
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
    public:
        void complain( std::string level );
};

#endif