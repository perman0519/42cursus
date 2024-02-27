//
// Created by Junsang Song on 1/23/24.
//

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
	std::cout << "WrongAnimal: Constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal: Destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &WrongAnimal) {
	std::cout << "WrongAnimal: Copy Constructor called" << std::endl;
	*this = WrongAnimal;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &WrongAnimal) {
	std::cout << "WrongAnimal: Copy assignment Operator called" << std::endl;
	if (this != &WrongAnimal) {
		this->type = WrongAnimal.type;
	}
	return  *this;
}

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal: makeSound called" << std::endl;
}

std::string WrongAnimal::getType() const { return this->type; }
