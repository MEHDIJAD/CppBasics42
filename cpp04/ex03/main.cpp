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
    Character *me = new Character("The Protagonist");

	AMateria *clone = e.clone();
	me->equip(clone); /* Each time we creat a clone = diffrent pointer */
	me->unequip(0);
	
	delete clone;
	delete me;

    return 0;
}
