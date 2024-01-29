//
// Created by Junsang Song on 1/23/24.
//
#include "Cat.hpp"
#include "Dog.hpp"

void a() {
	system("leaks a.out");
}

int main() {
	atexit(a);
    {
        std::cout << "=============================================================" << std::endl;
        Animal *animals[4];

        for (int i = 0; i < 4; ++i) {
            if (i % 2)
                animals[i] = new Dog();
            else
                animals[i] = new Cat();
        }

        *animals[1] = *animals[0];

        for (int i = 0; i < 4; ++i) {
            animals[i]->makeSound();
            std::cout << animals[i]->getType() << std::endl;
            delete animals[i];
        }
        std::cout << "=============================================================" << std::endl;
    }
    {
        Cat cat = Cat();
        Cat cat2(cat);
//        cat2 = cat;

        cat.makeSound();
        cat2.makeSound();
        std::cout << "=============================================================" << std::endl;
    }

	return 0;
}
