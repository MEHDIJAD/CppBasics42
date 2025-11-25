#include "Zombie.hpp"

int main(void)
{
    int N=5;
    Zombie *hord = zombieHorde(N, "rick");

    for(int i = 0; i < N; i++){
        hord[i].announce();
    }

    delete [] hord; /* We add [] to delet an array on the heap */

    return (0);
}
