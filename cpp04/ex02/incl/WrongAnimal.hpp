#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

#define RESET "\033[0m"
#define YELLOW "\033[33m"
#define RED "\033[31m"

class WrongAnimal
{
private:
   protected:
    std::string type;

   public:
    WrongAnimal(void);
    WrongAnimal(std::string type);
    WrongAnimal(const WrongAnimal &other);
    WrongAnimal &operator=(const WrongAnimal &other);
	~WrongAnimal();

    void SetType(const std::string type);
    std::string getType(void) const;

    void makeSound(void) const ;
};

#endif
