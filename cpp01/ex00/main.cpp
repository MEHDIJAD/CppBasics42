#include "Zombie.hpp"

/**
 * @brief Demonstrates the lifecycle of Zombie objects with different allocations.
 *
 * This function showcases two ways to create and destroy Zombie objects:
 * 1.  A Zombie is created on the heap via `newZombie()`, so it must be manually
 *     deleted to prevent memory leaks.
 * 2.  A Zombie is created on the stack inside `randomChump()`, and its memory is
 *     automatically freed when the function scope is exited.
 */
int main(void)
{
    Zombie *heapZombie = newZombie("Foo");
    heapZombie->announce();

    delete heapZombie; /* We clean HERE because the scopy and we return the pointer 
		so the caller have the resposabilty to clean */

    randomChump("Jack");
}
