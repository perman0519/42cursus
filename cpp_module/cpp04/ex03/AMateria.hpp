//
// Created by Junsang Song on 1/24/24.
//

#ifndef CPP04_AMATERIA_HPP
#define CPP04_AMATERIA_HPP

#include <string>
#include "IMateriaSource.hpp"

class ICharacter;

class AMateria : public IMateriaSource {
public:
	AMateria(std::string const & type);
	virtual ~AMateria();
	AMateria(const AMateria &aMateria);
	AMateria &operator=(const AMateria &aMateria);

	std::string const & getType() const;

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);

protected:
	AMateria();
	std::string _type;
};


#endif //CPP04_AMATERIA_HPP
