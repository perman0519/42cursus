/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:50:20 by junssong          #+#    #+#             */
/*   Updated: 2024/01/10 13:50:21 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {
}

Weapon::Weapon() {
}

Weapon::~Weapon() {
}

std::string Weapon::getType() {
    return _type;
}

void    Weapon::setType(std::string type) {
    this->_type = type;
}