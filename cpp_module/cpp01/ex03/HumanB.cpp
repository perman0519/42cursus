/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:00:56 by junssong          #+#    #+#             */
/*   Updated: 2024/01/11 13:40:45 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {}

HumanB::~HumanB () {}

void    HumanB::setWeapon(Weapon &weapon) {
    this->_weapon = &weapon;
}

void	HumanB::attack() {
    if (this->_weapon == NULL) {
        std::cout << this->_name << " dosen't have a Weapon" << std::endl;
        return ;
    }
    std::cout << this->_name
              << " attacks with their "
              << _weapon->getType() << std::endl;
}