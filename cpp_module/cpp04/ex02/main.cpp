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
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();
	const Animal *cat2 = cat;

	dog->makeSound();
	cat->makeSound();
	cat2->makeSound();

	delete dog;
	delete cat;
	delete cat2;
	return 0;
}
