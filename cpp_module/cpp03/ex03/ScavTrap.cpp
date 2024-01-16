/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:53:58 by junssong          #+#    #+#             */
/*   Updated: 2024/01/15 15:54:08 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    this->_name = name;
	ClapTrap::_energyPoints = 50;
	_hitPoints = 100;
	_attackDamage = 20;
	std::cout << "ScavTrap: " << _name << " Constructor called" << std::endl;
}

ScavTrap::~ScavTrap() {
	std::cout <<  "ScavTrap: " << this->_name << " Destructor called" << std::endl;
}

void	ScavTrap::attack(const std::string &target) {
	if (_energyPoints != 0) {
		std::cout <<"ScavTrap: " << this->_name <<
				  " attacks " << target <<
				  ", causing " << this->_attackDamage <<
				  " points of damage! " << std::endl;
		--_energyPoints;
	}
}

void	ScavTrap::guardGate() {
	std::cout << "ScavTrap: " << this->_name << " is now in Gate keeper mode." << std::endl;
}
