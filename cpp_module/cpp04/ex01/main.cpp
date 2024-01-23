//
// Created by Junsang Song on 1/23/24.
//
#include "Cat.hpp"
#include "Dog.hpp"

int main() {
	const Animal *animal = new Animal();
	const Dog *dog = new Dog();
	const Cat *cat = new Cat();

	Animal animal1;

	std::cout << animal->getType() << std::endl;
	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;

	animal->makeSound();
	dog->makeSound();
	cat->makeSound();
	animal1.makeSound();

	delete animal;
	delete dog;
	delete cat;
}