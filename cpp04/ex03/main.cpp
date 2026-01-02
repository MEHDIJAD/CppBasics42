#include "incl/AMateria.hpp"
#include "incl/Ice.hpp"
#include "incl/Cure.hpp"
#include "incl/Character.hpp"
#include "incl/IMateriaSource.hpp"
#include "incl/MateriaSource.hpp"

void SubjectTest()
{
	std::cout << BLUE << "\n=== TEST 1: SUBJECT BASIC TEST ===" << RESET << std::endl;
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");
	
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	
	tmp = src->createMateria("cure");
	me->equip(tmp);
	
	ICharacter* bob = new Character("bob");
	
	me->use(0, *bob);
	me->use(1, *bob);
	
	delete bob;
	delete me;
	delete src;
}

void TestDeepCopy()
{
	std::cout << YELLOW << "\n=== TEST 2: DEEP COPY CHECK ===" << RESET << std::endl;

	Character* original = new Character("Original");
	AMateria* m1 = new Ice();
	original->equip(m1);

	Character* copy = new Character(*original);

	delete original;

	std::cout << GREEN<< "Using copy (should work even after original is deleted):" << std::endl;
	ICharacter* target = new Character("Target");
	copy->use(0, *target);
	delete target;
	delete copy;
}

void TestInventoryFull()
{
	std::cout << BLUE << "\n=== TEST 3: FULL INVENTORY & LEAK CHECK ===" << RESET << std::endl;
	
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice()); // 0
	src->learnMateria(new Cure()); // 1
	src->learnMateria(new Ice()); // 2
	src->learnMateria(new Cure()); // 3
	

	src->learnMateria(new Ice()); // 4 (Overflow)

	Character* me = new Character("Me");
	
	// Equip 4 items
	for (int i = 0; i < 4; i++)
		me->equip(src->createMateria("ice"));

	AMateria* extra = src->createMateria("cure");
	me->equip(extra); 

	delete me;
	delete src;
}

void TestUnequip()
{
	std::cout << BLUE << "\n=== TEST 4: UNEQUIP (FLOOR) CHECK ===" << RESET << std::endl;
	ICharacter* me = new Character("Me");
	AMateria* ice = new Ice();
	
	me->equip(ice);
	
	me->unequip(0);
	
	ICharacter* bob = new Character("Bob");
	me->use(0, *bob); 

	delete ice; 

	delete bob;
	delete me;
}

void TestalreadyExist(void)
{
	IMateriaSource* src = new MateriaSource();
	AMateria* tmp = new Ice();

	ICharacter *inter = new Character();
	AMateria *temp = new Ice();

	inter->equip(temp);
	inter->equip(temp);

	src->learnMateria(tmp);
	src->learnMateria(tmp);

	delete src;
	delete inter;
}


int main()
{
	SubjectTest();
	TestDeepCopy();
	TestInventoryFull();
	TestUnequip();
	TestalreadyExist();
	return 0;
}