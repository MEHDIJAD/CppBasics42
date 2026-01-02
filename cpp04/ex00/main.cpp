#include "incl/Animal.hpp"
#include "incl/Dog.hpp"
#include "incl/Cat.hpp"
#include "incl/WrongCat.hpp"
#include "incl/WrongAnimal.hpp"


void SubjectTest(void)
{
	// =========================================================================
	// TEST 1: SUBJECT TESTS (Basic Polymorphism)
	// =========================================================================
	std::cout << BLUE << "=== TEST 1: SUBJECT TESTS ===" << RESET << std::endl;

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout  << YELLOW << "j Type: " << RESET << j->getType() << " " << std::endl;
	std::cout << YELLOW << "i Type: " << RESET << i->getType() << " " << std::endl;
	
	std::cout << GREEN << "Expected: Cat Sound | Actual: ";
	i->makeSound();
	
	std::cout << BLUE << "Expected: Dog Sound | Actual: ";
	j->makeSound();

	std::cout << YELLOW << "Expected: Animal Sound | Actual: ";
	meta->makeSound();

	delete j;
	delete i;
	delete meta;
	std::cout << std::endl;

}


void WrongAnimalTest(void)
{
	// =========================================================================
	// TEST 2: WRONG ANIMAL (Static Binding Demonstration)
	// =========================================================================
	std::cout << BLUE << "=== TEST 2: WRONG ANIMAL TESTS ===" << RESET << std::endl;
	
	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout  << GREEN << "WrongCat Type: " << wrongCat->getType() << " " << std::endl;

	std::cout << RED << "Expected: WrongAnimal Sound (No Virtual) | Actual: ";
	wrongCat->makeSound();

	std::cout << RED << "Expected: WrongAnimal Sound | Actual: ";
	wrongMeta->makeSound();

	delete wrongCat;
	delete wrongMeta;
	std::cout << std::endl;

}

void DirObjPointerTest(void)
{
	// =========================================================================
	// TEST 3: DIRECT OBJECT VS POINTER (The "Hidden" Function)
	// =========================================================================
	std::cout << BLUE << "=== TEST 3: DIRECT INSTANTIATION VS POINTER ===" << RESET << std::endl;
	
	WrongCat rawCat; /* this is a Stack object */
	std::cout << "Calling makeSound() on a raw WrongCat object: ";
	rawCat.makeSound();

	WrongAnimal* ptrToRaw = &rawCat;
	std::cout << "Calling makeSound() on WrongAnimal* pointing to same object: ";
	ptrToRaw->makeSound();
	std::cout << std::endl;
}

void CpyConstTest(void)
{
	// =========================================================================
	// TEST 4: CANONICAL FORM (Copy Constructor)
	// =========================================================================
	std::cout << BLUE << "=== TEST 4: COPY CONSTRUCTOR BASICS ===" << RESET << std::endl;
	
	Dog originalDog;
	Dog copyDog(originalDog);

	std::cout << "Original Type: " << originalDog.getType() << std::endl;
	std::cout << "Copy Type: " << copyDog.getType() << std::endl;
	
	std::cout << "Original Sound: "; originalDog.makeSound();
	std::cout << "Copy Sound: "; copyDog.makeSound();
	
	std::cout << std::endl;
}

void TestLeakDestructor(void)
{
	// =========================================================================
	// TEST 5: Virtual Destructor
	// =========================================================================
	std::cout << BLUE << "=== TEST 5: Virtual Destructor ===" << RESET << std::endl;
	WrongAnimal *meta = new WrongCat();

	delete meta;
}


/**
 * @brief Tests the Dog assignment operator to ensure the base class 'type'
 */
void AssigOpBaseTest( void )
{
	Dog dogA;
	Dog dogB;

	dogA.setType("Pitbull");
	dogB.setType("Malinois");

	dogA = dogB; // Calls Dog::operator=, which should call Animal::operator=

	std::cout << dogA.getType() << std::endl;
	std::cout << dogB.getType() << std::endl;
}

void CloneConstTest( void )
{
	Dog original;
	original.setType("SuperDog");
	
	Dog cpy(original);
	std::cout << "Original Type: " << original.getType() << std::endl;
	std::cout << "Clone Type:    " << cpy.getType() << std::endl;
}

int main(void)
{
	// SubjectTest();
	// WrongAnimalTest();
	// DirObjPointerTest();
	// CpyConstTest();
	// TestLeakDestructor();
	// AssigOpBaseTest();
	// CloneConstTest();
	
	return 0;
}
