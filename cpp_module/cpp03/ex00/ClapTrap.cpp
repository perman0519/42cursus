/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:02:49 by junssong          #+#    #+#             */
/*   Updated: 2024/01/15 15:06:18 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) {
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
     std::cout << this->_name << " Constructor called" << std::endl;
}

ClapTrap::~ClapTrap() {
     std::cout << this->_name << " Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &clapTrap) {
	std::cout << "Copy constructor called" << std::endl;
	if (this != &clapTrap) {
		this->_name = clapTrap._name;
		this->_hitPoints = clapTrap._hitPoints;
		this->_energyPoints = clapTrap._energyPoints;
		this->_attackDamage = clapTrap._attackDamage;
	}
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &clapTrap) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &clapTrap) {
		this->_name = clapTrap._name;
		this->_hitPoints = clapTrap._hitPoints;
		this->_energyPoints = clapTrap._energyPoints;
		this->_attackDamage = clapTrap._attackDamage;
	}
	return *this;
}

const std::string &ClapTrap::getName() const {
	return this->_name;
}

void	ClapTrap::attack(const std::string &target) {
	if (_energyPoints != 0) {
		std::cout <<"ClapTrap " << this->_name <<
					" attacks " << target <<
					", causing " << this->_attackDamage <<
					" points of damage! " << std::endl;
		--_energyPoints;
	}
}

void	ClapTrap::takeDamage(unsigned int amount) {
	std::cout <<"ClapTrap " << this->_name <<
				" took damage, causing " << amount <<
				" points of damage! " << std::endl;
	_hitPoints -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (_energyPoints != 0) {
		std::cout <<"ClapTrap " << this->_name <<
				  " is repaired " << amount <<
				  " points." << std::endl;
		_hitPoints += amount;
		--_energyPoints;
	}
}

const unsigned int &ClapTrap::getEnergyPoints() const {
	return this->_energyPoints;
}

const unsigned int &ClapTrap::getHitPoints() const {
	return this->_hitPoints;
}

const unsigned int &ClapTrap::getAttackDamage() const {
	return this->_attackDamage;
}

