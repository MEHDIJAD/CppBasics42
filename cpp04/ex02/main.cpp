#include "incl/Animal.hpp"
#include "incl/Dog.hpp"
#include "incl/Cat.hpp"
#include "incl/Brain.hpp"

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define RESET   "\033[0m"

int main(void)
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;//should not create a leak
	delete i;

	// ========================================================================
    // TEST 1: The Subject Requirement (Array of Animals)
    // ========================================================================
    std::cout << GREEN << "\n\n--- TEST 1: ARRAY OF ANIMALS ---" << RESET << std::endl;

	const int arraySize = 4;
	const Animal *animals[arraySize];
	
	for (int i = 0; i < arraySize / 2; i++){
		animals[i] = new Dog();
	}
	for (int i = arraySize / 2; i < arraySize; i++){
		animals[i] = new Cat();
	}

	std::cout << "\n" << RED << "--- DELETING ARRAY ---" << RESET << std::endl;

	for (int i = 0; i < arraySize; i++){
		delete animals[i];
	}

	// ========================================================================
    // TEST 2.0: Deep Copy Proof (Copy Constructor)
    // ========================================================================
    std::cout << "\n" << GREEN << "--- TEST 2: DEEP COPY (CONSTRUCTOR) ---" << RESET << std::endl;

	Dog *original = new Dog();
	std::cout  << GREEN << "original Created\n\n";
	
	Dog *copy = new Dog (*original);
	std::cout << GRAY << "Copy created (Should have its OWN Brain).\n\n";
	
	std::cout << RED << "Deleting Original..." << std::endl;
    delete original; 

	std::cout << RED << "\n\nDeleting Copy..." << std::endl;
    delete copy; 

	// ========================================================================
    // TEST 3: Assignment Operator (Brain Transplant)
    // ========================================================================
    std::cout << "\n" << GREEN << "--- TEST 3: ASSIGNMENT OPERATOR ---" << RESET << std::endl;

	Dog dogA;
    Dog dogB;

    std::cout  << GREEN << "\n\nAssigning B = A...\n" << std::endl;
    dogB = dogA;

	return 0;
}
