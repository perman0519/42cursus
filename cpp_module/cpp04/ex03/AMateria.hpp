//
// Created by Junsang Song on 1/24/24.
//

#ifndef CPP04_AMATERIA_HPP
#define CPP04_AMATERIA_HPP

#include <string>

class AMateria {
public:
	AMateria(std::string const & type);
	~AMateria();
	AMateria &operator=(const std::string &type);

	std::string const & getType() const;

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);

protected:
	AMateria();
	std::string type;
};


#endif //CPP04_AMATERIA_HPP
