//
// Created by Junsang Song on 1/25/24.
//

#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {

}

Ice::~Ice() {

}

Ice::Ice(const Ice &ice) {
	*this = ice;
}

Ice &Ice::operator=(const Ice &ice) {
	if (this != &ice)
		this->_type = ice._type;
	return *this;
}

AMateria *Ice::clone() const {
	return new Ice();
}

void Ice::use(ICharacter &target) {
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
