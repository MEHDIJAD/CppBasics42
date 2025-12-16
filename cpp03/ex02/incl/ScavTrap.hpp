#ifndef _SCAVTRAP_HPP_
#define _SCAVTRAP_HPP_

#include "ClapTrap.hpp"

// ANSI Color Codes
#define RESET   "\033[0m"
#define YELLOW  "\033[33m"

class ScavTrap : public ClapTrap
{
	private:

	public:
		/*! @brief Default Constructor */
		ScavTrap( void );
		/*! @brief Paramerize Costructor that take @param Name */
		ScavTrap(std::string Name);
		/* Copy Constructor */
		ScavTrap(const ScavTrap &other);
		/* Assigment Operator */
		ScavTrap &operator=(const ScavTrap &other);
		/*! @brief Destructor */
		~ScavTrap( void );
		/*! @brief display a message indicating that ScavTrap is now in Gate keeper mode.*/
		void guardGate( void );

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif