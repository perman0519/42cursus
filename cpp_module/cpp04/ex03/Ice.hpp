//
// Created by Junsang Song on 1/25/24.
//

#ifndef CPP04_ICE_HPP
#define CPP04_ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria {
/*               AMateria               */
public:
//	AMateria(std::string const & type);
//	virtual ~AMateria();
//	AMateria(const AMateria &aMateria);
//	AMateria &operator=(const AMateria &aMateria);
//
//	std::string const & getType() const;
//
//	virtual void use(ICharacter& target);
	Ice();
	~Ice();
	Ice(const Ice &ice);
	Ice &operator=(const Ice &ice);
	virtual AMateria* clone() const;
	virtual void use(ICharacter &target);

//protected:
//	AMateria();
//	std::string type;
};


#endif //CPP04_ICE_HPP
