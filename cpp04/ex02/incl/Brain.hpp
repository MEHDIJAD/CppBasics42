#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

#define RESET "\033[0m"
#define GRAY "\033[90m"

class Brain
{
	private:
		std::string ideas[100];

	public:
		Brain();
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);
		~Brain();
};

#endif
