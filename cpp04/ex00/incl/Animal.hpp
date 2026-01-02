#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

#define RESET "\033[0m"
#define YELLOW "\033[33m"

class Animal
{
   private:

   protected:
	std::string type;

   public:
	/* Default Constructor */
	Animal(void);
	/* Paramertize Constructor */
	Animal(std::string &type);
	/* Copy Costructor */
	Animal(const Animal &other);
	/* Assigment Operator */
	Animal &operator=(const Animal &other);
	/* Destructor */
	/**
	* @brief Destroys the Animal object.
	* * @note This destructor is virtual. This ensures that when a derived object 
	* (like Dog or Cat) is deleted through a pointer to the base Animal class, 
	* the derived class's destructor is called first. This prevents memory leaks.
	*/
	virtual ~Animal();

	/*! @brief It returns a "read-only link" to the actual variable stored inside the class. 
	No copying happens. 
	It is instant and free, regardless of how long the string is.
	*/
	std::string const &getType(void) const;

	// void setType(std::string type);

	/**
	* @brief Prints the specific sound of the animal.
	* * This function is virtual to allow derived classes (like Dog and Cat) 
	* to override it and output their unique sounds.
	*/
	virtual void makeSound(void) const ;
};

#endif
