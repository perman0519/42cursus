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
    this->_attackDamage = FragTrap::_attackDamage;
    this->_hitPoints = FragTrap::_hitPoints;
    this->_energyPoints = ScavTrap::_energyPoints;
}

DiamondTrap::~DiamondTrap() {}

void DiamondTrap::whoAmI() {
    std::cout << "This name is " << this->name << ", ClapTrap's name is " << ClapTrap::_name << std::endl;
}

