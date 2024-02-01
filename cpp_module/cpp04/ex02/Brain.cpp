//
// Created by Junsang Song on 1/23/24.
//

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain: Constructor called" << std::endl;
	// this->ideas = new std::string[100];
}

Brain::~Brain() {
	std::cout << "Brain: Destructor called" << std::endl;
}

Brain::Brain(const Brain &brain) {
	std::cout << "Brain: Copy Constructor called" << std::endl;
	*this = brain;
}

Brain &Brain::operator=(const Brain &brain) {
	std::cout << "Brain: Copy assignment Operator called" << std::endl;
	if (this != &brain) {
		for (size_t i = 0; i < 100; i++)
		{
			this->ideas[i] = brain.ideas[i];
		}
	}
	return  *this;
}

const std::string *Brain::getIdeas() const { return ideas; }
