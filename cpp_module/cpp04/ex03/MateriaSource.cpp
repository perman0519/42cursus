//
// Created by Junsang Song on 1/25/24.
//

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; ++i) {
		this->aMaterias[i] = NULL;
	}
}

MateriaSource::~MateriaSource() {}

MateriaSource::MateriaSource(const MateriaSource &materiaSource) {
	*this = materiaSource;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &materiaSource) {
	if (this != &materiaSource) {

	}
	return *this;
}

void MateriaSource::learnMateria(AMateria *aMateria) {
	for (int i = 0; i < 4; ++i) {
		if (this->aMaterias[i] != NULL) {
			aMaterias[i] = aMateria;
			return ;
		}
	}
}

AMateria *MateriaSource::createMateria(const std::string &type) {
	for (int i = 0; i < 4; ++i) {
		if (this->aMaterias[i] != NULL && (this->aMaterias[i]).getType() == type) {

		}
	}
}
