//
// Created by Junsang Song on 1/25/24.
//

#ifndef CPP04_CHARACTER_HPP
#define CPP04_CHARACTER_HPP

#include "ICharacter.hpp"
class Character : ICharacter {
public:
/*                     ICharacter                   */
//	virtual ~ICharacter() {}
	virtual std::string const & getName();
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);

private:

};


#endif //CPP04_CHARACTER_HPP
