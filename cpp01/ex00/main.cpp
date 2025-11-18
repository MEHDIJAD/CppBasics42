#include "Zombie.hpp"


int main(void)
{
    Zombie *heapZombie = newZombie("ali");
    heapZombie->announce();

    delete heapZombie;

    randomChump("mehdi");
}


