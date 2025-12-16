#include "ClapTrap.hpp"
#include <iostream>

int main(void)
{
	std::cout << "|- ClapTrap TEST -|" << std::endl;
	ClapTrap clap("MARK-1");
	clap.attack("Target-1");
	clap.takeDamage(8);
	std::cout  << "HP: " << clap.getHitPoints() << std::endl;
	clap.beRepaired(11);
	clap.takeDamage(20);
	clap.attack("Target-1");

	return (0);
}
