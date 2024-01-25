//
// Created by Junsang Song on 1/25/24.
//

#ifndef CPP04_ICE_HPP
#define CPP04_ICE_HPP

#include "AMateria.hpp"

class Ice : AMateria {
/*               AMateria               */
public:
//	AMateria(std::string const & type);
//	virtual ~AMateria();
//	AMateria(const AMateria &aMateria);
//	AMateria &operator=(const AMateria &aMateria);
//
//	std::string const & getType() const;
//
	virtual AMateria* clone() const;
//	virtual void use(ICharacter& target);
//
//protected:
//	AMateria();
//	std::string type;
private:
};


#endif //CPP04_ICE_HPP
