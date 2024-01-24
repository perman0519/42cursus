//
// Created by Junsang Song on 1/23/24.
//

#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain: Constructor called" << std::endl;
	this->ideas = new std::string[100];
}

Brain::~Brain() {
	std::cout << "Brain: Destructor called" << std::endl;
	delete [] this->ideas;
}

Brain::Brain(const Brain &brain) {
	std::cout << "Brain: Copy Constructor called" << std::endl;
	*this = brain;
}

Brain &Brain::operator=(const Brain &brain) {
	std::cout << "Brain: Copy assignment Operator called" << std::endl;
	if (this != &brain) {
		this->ideas = brain.ideas;
	}
	return  *this;
}

const std::string *Brain::getIdeas() const { return ideas; }
