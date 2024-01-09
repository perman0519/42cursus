#include "Zombie.h"

Zombie*	zombieHorde( int N, std::string name ) {
    Zombie *zombieArr;
    Zombie &(*tmp) = zombieArr;
    for (int i = 0; i < N; ++i) {
        zombieArr = new Zombie(name);
        zombieArr++;
    }
    return tmp;
}