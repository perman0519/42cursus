//
// Created by Junsang Song on 1/23/24.
//

#include "Cat.hpp"

Cat::Cat() : Animal() {
	std::cout << "Cat: Constructor called" << std::endl;
	this->type = "Cat";
	this->brain = new Brain();
}

Cat::~Cat() {
	std::cout << "Cat: Destructor called" << std::endl;
	delete brain;
}

Cat::Cat(const Cat &cat) : Animal() {
	std::cout << "Cat: Copy Constructor called" << std::endl;
	this->brain = new Brain();
	*this = cat;
}

Cat &Cat::operator=(const Cat &cat) {
	std::cout << "Cat: Copy assignment Operator called" << std::endl;
	if (this == &cat) {
		return *this;
	}
	delete brain;
	brain = new Brain();
	*brain = *(cat.brain);
	this->type = cat.type;
	return *this;
}

void	Cat::makeSound() const {
	std::cout << "miumiu" << std::endl;
}
