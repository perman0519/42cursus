//
// Created by Junsang Song on 1/23/24.
//

#include "Dog.hpp"

Dog::Dog() : Animal() {
	std::cout << "Dog: Constructor called" << std::endl;
	this->type = "Dog";
}

Dog::~Dog() {
	std::cout << "Dog: Destructor called" << std::endl;
}

Dog::Dog(const Dog &dog) : Animal() {
	std::cout << "Dog: Copy Constructor called" << std::endl;
	*this = dog;
}

Dog &Dog::operator=(const Dog &dog) {
	std::cout << "Dog: Copy assignment Operator called" << std::endl;
	if (this != &dog) {
		this->type = dog.type;
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Bark!! Bark!!" << std::endl;
}