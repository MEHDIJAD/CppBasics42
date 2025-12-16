#ifndef _DIAMONDTRAP_HPP_
#define _DIAMONDTRAP_HPP_

#include <string.h>
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

/* Multy inheritance */
class DiamondTrap : public FragTrap , public ScavTrap
{
	private:
		std::string _Name; //* // <--- The "Shadow" Name (This hides ClapTrap::_Name)

	public:
		/* Default Constructor */
		DiamondTrap(void);
		/* Paramertize Costructor */
		DiamondTrap(std::string Name);
		/* Copy Costructor */
		DiamondTrap(const DiamondTrap &other);
		/* Assigment Operator */
		DiamondTrap &operator=(const DiamondTrap &other);
		/* Destructor */
		~DiamondTrap( void );

		void whoAmI();
		void attack(const std::string &target);
};

#endif