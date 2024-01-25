//
// Created by Junsang Song on 1/25/24.
//

#ifndef CPP04_MATERIASOURCE_HPP
#define CPP04_MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource {
public:
	MateriaSource();
	~MateriaSource();
	MateriaSource(const MateriaSource &materiaSource);
	MateriaSource &operator=(const MateriaSource &materiaSource);


	virtual void learnMateria(AMateria* aMateria);
	virtual AMateria* createMateria(std::string const & type);

private:
	AMateria *_materiaSource[4];
};


#endif //CPP04_MATERIASOURCE_HPP
