//
// Created by Junsang Song on 1/25/24.
//

#ifndef CPP04_CHARACTER_HPP
#define CPP04_CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter {
public:
/*                     ICharacter                   */
//	virtual ~ICharacter() {}
	Character(std::string name);
	virtual ~Character();
	Character(const Character &character);
	Character &operator=(const Character &character);

	virtual std::string const & getName() const ;
	virtual void equip(AMateria* m);
	virtual void unequip(int idx);
	virtual void use(int idx, ICharacter& target);

private:
	Character();
	std::string _name;
	AMateria *_inventory[4];

};


#endif //CPP04_CHARACTER_HPP
