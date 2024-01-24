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
	const Animal *animal = new Cat();

	animal->makeSound();
	delete animal;

	return 0;
}