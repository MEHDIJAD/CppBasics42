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
		Brain( void );
		Brain(const Brain& other);
		Brain& operator=(const Brain& other);
		~Brain();

		/*! @note Help for testing if Copy Constructor works? (deep copy)*/
		const std::string& getIdea(int index) const;
		void setIdea(int index, const std::string& idea);
};

#endif
