//
// Created by Junsang Song on 1/24/24.
//

#include "AMateria.hpp"

AMateria::AMateria(const std::string &type) {
	this->_type = type;
}

AMateria::~AMateria() {}

AMateria::AMateria() : _type("") {}

AMateria::AMateria(const AMateria &aMateria) {
	*this = aMateria;
}

AMateria &AMateria::operator=(const AMateria &aMateria) {
	if (this != &aMateria) {
		this->_type = aMateria._type;
	}
	return *this;
}

std::string const &AMateria::getType() const { return this->_type; }

void AMateria::use(ICharacter &target) {

}