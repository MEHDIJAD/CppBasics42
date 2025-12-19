#include "incl/Animal.hpp"
#include "incl/Dog.hpp"
#include "incl/Cat.hpp"
#include "incl/WrongCat.hpp"
#include "incl/WrongAnimal.hpp"

int main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete j;
    delete i;
    delete meta;

	std::cout << std::endl;
	std::cout << YELLOW << "WRONG ANIMAL TEST:" << std::endl;

	const WrongAnimal *wrong = new WrongCat();
	std::cout << wrong->getType() << std::endl;

	wrong->makeSound();

	delete  wrong;
	
	return 0;
}
