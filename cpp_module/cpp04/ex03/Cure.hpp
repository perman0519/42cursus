//
// Created by Junsang Song on 1/25/24.
//

#ifndef CPP04_CURE_HPP
#define CPP04_CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria {
/*                  AMateria                    */
public:
//	AMateria(std::string const & type);
//	virtual ~AMateria();
//	AMateria(const AMateria &aMateria);
//	AMateria &operator=(const AMateria &aMateria);
//
//	std::string const & getType() const;
//
//	virtual void use(ICharacter& target);

	Cure();
	~Cure();
	Cure(const Cure &cure);
	Cure &operator=(const Cure &cure);
	virtual void use(ICharacter &target);

	virtual AMateria* clone() const;

//protected:
//	std::string type;
};

#endif //CPP04_CURE_HPP
