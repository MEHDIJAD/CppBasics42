#include "ScavTrap.hpp"
#include <iostream>

int main(void)
{
	std::cout << "|- ClapTrap TEST -|" << std::endl;
	ClapTrap clap("MARK-1");
	clap.attack("Target-1");
	clap.takeDamage(8);
	clap.beRepaired(11);

	std::cout << std::endl;

	std::cout << "|- ScavTrap TEST -|" << std::endl;
	ScavTrap p("MAEK-2");
	p.attack("Cat-1");
	p.takeDamage(8);
	p.beRepaired(11);
	p.guardGate();
	
	return (0);
}
