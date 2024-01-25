//
// Created by Junsang Song on 1/25/24.
//

#ifndef CPP04_IMATERIASOURCE_HPP
#define CPP04_IMATERIASOURCE_HPP

#include <string>

class AMateria;

class IMateriaSource {
public:
	virtual ~IMateriaSource() {}
	virtual void learnMateria(AMateria*) = 0;
	virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif //CPP04_IMATERIASOURCE_HPP
