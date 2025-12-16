#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <string>

// ANSI Color Codes
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"


class ClapTrap
{
	private:

	/*! @brief 
	The "Protected" Keyword
	In your ClapTrap.hpp, we moved attributes from private to protected.
	Private: Only ClapTrap can touch these variables. If ScavTrap tries to change _HitPoint, the compiler shouts.
	Protected: ClapTrap shares these variables only with its children (like ScavTrap).
	Public: Everyone (including main.cpp) can touch them (Bad encapsulation!).
	*/
	protected:
		/*! @brief @param Name passed as a parameter to the constructor */
		std::string _Name;
		/*! @brief Hit points (10), Representing the health of the ClapTrap */
		unsigned int _HitPoint;
		/* Energy points (10) */
		unsigned int _EnergyPoint;
		/* Attack damage (0) */
		unsigned int _AttackDamage;

	public:
		/* Default Constructor */
		ClapTrap( void );
		/* Parametrize Constructor (REQ) */
		ClapTrap(std::string Name);
		/* Copy Costructor */
		ClapTrap(const ClapTrap &other);
		/* Assigment Operator */
		ClapTrap &operator=(const ClapTrap &other);
		/* Destorctor */
		~ClapTrap( void );

		/* Setter Func */
		void setName(std::string const Name);
		/* Getter Func */
		std::string getName( void ) const;
		unsigned int getHitPoints( void ) const;
		
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);


};

#endif
