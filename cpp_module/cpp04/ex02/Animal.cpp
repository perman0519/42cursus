//
// Created by Junsang Song on 1/23/24.
//

#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << "Animal: Constructor called" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal: Destructor called" << std::endl;
}

Animal::Animal(const Animal &animal) {
	std::cout << "Animal: Copy Constructor called" << std::endl;
	*this = animal;
}

Animal &Animal::operator=(const Animal &animal) {
	std::cout << "Animal: Copy assignment Operator called" << std::endl;
	if (this != &animal) {
		this->type = animal.type;
	}
	return  *this;
}

std::string Animal::getType() const { return this->type; }
