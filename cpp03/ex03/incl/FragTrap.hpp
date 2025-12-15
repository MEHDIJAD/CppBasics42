#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

// ANSI Color Codes
#define CYAN    "\033[36m"

class FragTrap : virtual public ClapTrap
{
	public:
		// Constructors and Destructor
		FragTrap( void );
		FragTrap( std::string name );
		FragTrap( const FragTrap &other );
		~FragTrap( void );

		// Operator overloads
		FragTrap &operator=( const FragTrap &other );

		// Member functions
		void attack( const std::string& target );
		void highFivesGuys( void );
};

#endif
