/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:24:22 by junssong          #+#    #+#             */
/*   Updated: 2024/01/16 15:24:23 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(_name), FragTrap(_name), name(name) {
	std::cout << "DiamondTrap: name constructor called" << std::endl;
	this->_attackDamage = FragTrap::_attackDamage;
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::_energyPoints;
}

DiamondTrap::DiamondTrap() {}

DiamondTrap::~DiamondTrap() {
	std::cout <<  "ClapTrap: " << this->_name << " Destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &diamondTrap) : ClapTrap(diamondTrap._name), ScavTrap(diamondTrap._name), FragTrap(diamondTrap._name) {
	std::cout << "DiamondTrap: Copy constructor called" << std::endl;
	*this = diamondTrap;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &diamondTrap) {
	std::cout << "DiamondTrap: Copy assignment operator called" << std::endl;
	if (this != &diamondTrap) {
		this->_name = diamondTrap._name;
		this->_attackDamage = diamondTrap._attackDamage;
		this->_hitPoints = diamondTrap._hitPoints;
		this->_energyPoints = diamondTrap._energyPoints;
		this->name = diamondTrap.name;
	}
	return *this;
}

void DiamondTrap::whoAmI() {
    std::cout << "This name is " << this->name << ", ClapTrap's name is " << ClapTrap::_name << std::endl;
}

