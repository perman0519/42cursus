//
// Created by Junsang Song on 1/24/24.
//

#ifndef CPP04_AMATERIA_HPP
#define CPP04_AMATERIA_HPP

#include <string>
#include <iostream>
#include "ICharacter.hpp"

//class ICharacter;

/*----------abstract Class-----*/
class AMateria {
public:
	AMateria(std::string const & type);

	AMateria();
	virtual ~AMateria();
	AMateria(const AMateria &aMateria);
	AMateria &operator=(const AMateria &aMateria);

	std::string const & getType() const;

	/*----------abstract Class-----*/
	virtual void use(ICharacter& target) = 0;
	virtual AMateria* clone() const = 0;

protected:
	std::string _type;
};


#endif //CPP04_AMATERIA_HPP
