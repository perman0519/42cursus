//
// Created by Junsang Song on 1/25/24.
//

#include "Character.hpp"

Character::Character() {
	for (int i = 0; i < 4; ++i) {
		this->_inventory[i] = NULL;
	}
}

Character::~Character() {
	for (int i = 0; i < 4; ++i) {
	  	if(this->_inventory[i] != NULL)
			  delete this->_inventory[i];
	}
}

Character::Character(std::string name) : _name(name) {
	for (int i = 0; i < 4; ++i) {
		this->_inventory[i] = NULL;
	}
}

Character::Character(const Character &character) : _name(character.getName()) {
	*this = character;
}

Character &Character::operator=(const Character &character) {
	if (this != &character) {
		for (int i = 0; i < 4; ++i) {
			if (character._inventory[i] != NULL) {
				if (this->_inventory[i] != NULL)
					delete this->_inventory[i];
				this->_inventory[i] = NULL;
				equip(character._inventory[i]->clone());
			}
		}
	}
	return *this;
}

std::string const &Character::getName() const { return this->_name; }

void Character::equip(AMateria *m) {
	for (int i = 0; i < 4; ++i) {
		if (this->_inventory[i] == NULL) {
			this->_inventory[i] = m;
			break;
		}
		else {
			if (this->_inventory[i] == m)
			return ;
		}
	}
}

void Character::unequip(int idx) {
	if (idx > 3)
		return ;
	Floor::put(this->_inventory[idx]);
	this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter &target) {
	if (idx > 3)
		return;
	if (this->_inventory[idx] != NULL) {
		this->_inventory[idx]->use(target);
	}
}
