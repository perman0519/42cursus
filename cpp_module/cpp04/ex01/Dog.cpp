//
// Created by Junsang Song on 1/23/24.
//

#include "Dog.hpp"

Dog::Dog() : Animal() {
	this->type = "Dog";
	this->brain = new Brain;
	std::cout << "Dog: Constructor called" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog: Destructor called" << std::endl;
	delete brain;
}

Dog::Dog(const Dog &dog) : Animal() {
	std::cout << "Dog: Copy Constructor called" << std::endl;
	this->brain = new Brain();
	*this = dog;
}

Dog &Dog::operator=(const Dog &dog) {
	std::cout << "Dog: Copy assignment Operator called" << std::endl;
	if (this == &dog) {
		return *this;
	}
	delete brain;
	brain = new Brain();
	*brain = *(dog.brain);
	this->type = dog.type;
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Bark!! Bark!!" << std::endl;
}
