#include "Zombie.hpp"

int main(void)
{
    int N=5;
    Zombie *hord = zombieHorde(N, "ali");

    for(int i = 0; i < N; i++){
        hord[i].announce();
    }

    delete [] hord;

    return (0);
}
