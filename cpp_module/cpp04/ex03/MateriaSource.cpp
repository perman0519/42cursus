//
// Created by Junsang Song on 1/25/24.
//

#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"

MateriaSource::MateriaSource() {
//	this->_materiaSource = new AMateria[4];
 	for (int i = 0; i < 4; ++i) {
		this->_materiaSource[i] = NULL;
	}
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; ++i) {
		if (this->_materiaSource[i] != NULL)
			delete this->_materiaSource[i];
	}
}

MateriaSource::MateriaSource(const MateriaSource &materiaSource) {
	*this = materiaSource;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &materiaSource) {
	if (this != &materiaSource) {
		for (int i = 0; i < 4; ++i) {
			if (materiaSource._materiaSource[i] != NULL)
				this->learnMateria(materiaSource._materiaSource[i]->clone());
		}
	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *aMateria) {
	for (int i = 0; i < 4; ++i) {
		if (this->_materiaSource[i] == NULL) {
			this->_materiaSource[i] = aMateria;
			return ;
		}
		else {
			if (this->_materiaSource[i] == aMateria)
				return ;
		}
	}
}

AMateria *MateriaSource::createMateria(const std::string &type) {
	AMateria *a = NULL;
	for (int i = 0; i < 4; ++i) {
		if (this->_materiaSource[i] != NULL && (this->_materiaSource[i])->getType() == type) {
			a = this->_materiaSource[i]->clone();
			break;
		}
	}
	return a;
}
