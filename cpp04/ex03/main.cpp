#include "incl/AMateria.hpp"
#include "incl/Ice.hpp"
#include "incl/Cure.hpp"
#include "incl/Character.hpp"

void Test01(void ){
	Ice i;
    std::cout << std::endl;
    Cure j;
    std::cout << std::endl;
    
    AMateria *clone = i.clone(); 
    // clone return a pointer to AMateria, 
    // We NEED to catch it in a Var and delet it  after finish

    std::cout  << clone->getType() << std::endl;
    delete clone;

}

int main(void)
{

	// Test01()
	Ice e;
	Cure c;
	
    Character *me = new Character("The Protagonist");

	Character *bob = new Character("Bob");

	// Create the pointer and SAVE it in a variable
	AMateria *ice = e.clone();
	AMateria *cure = c.clone();
	me->equip(ice); /* Each time we creat a clone = diffrent pointer */
	me->equip(cure);
	me->use(0, *bob);
	me->use(1, *bob);
	me->unequip(0);
	delete ice;

	
	// delete cure;
	delete me;
	delete bob;

    return 0;
}
