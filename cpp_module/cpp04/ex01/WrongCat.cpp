//
// Created by Junsang Song on 1/23/24.
//

#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	std::cout << "WrongCat: Constructor called" << std::endl;
	this->type = "WrongCat";
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat: Destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &WrongCat) : WrongAnimal() {
	std::cout << "WrongCat: Copy Constructor called" << std::endl;
	*this = WrongCat;
}

WrongCat &WrongCat::operator=(const WrongCat &WrongCat) {
	std::cout << "WrongCat: Copy assignment Operator called" << std::endl;
	if (this != &WrongCat) {
		this->type = WrongCat.type;
	}
	return *this;
}

void	WrongCat::makeSound() const {
	std::cout << "miumiu" << std::endl;
}
