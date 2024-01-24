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

	delete dog;
	delete cat;

	return 0;
}