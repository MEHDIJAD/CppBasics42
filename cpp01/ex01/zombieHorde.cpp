#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
    if (N <= 0)
        return (NULL);
	/*!
	@brief This single line allocates an array of N zombies on the heap, 
		calls the default constructor for each one, 
		and makes the zombieHord pointer point to the beginning of that array.
	*/
    Zombie *zombieHord = new Zombie[N];
    for (int i = 0; i < N; i++)
        zombieHord[i].setName(name);
    return (zombieHord);
}