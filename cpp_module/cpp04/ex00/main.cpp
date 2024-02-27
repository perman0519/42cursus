//
// Created by Junsang Song on 1/23/24.
//
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main() {
	const Animal *animal = new Animal();
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();
	const WrongAnimal *wrongCat = new WrongCat();

	Animal animal1;

	std::cout << animal->getType() << std::endl;
	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;

	animal->makeSound();
	dog->makeSound();
	cat->makeSound();
	animal1.makeSound();
	wrongCat->makeSound();

	delete animal;
	delete dog;
	delete cat;
	delete wrongCat;
}
