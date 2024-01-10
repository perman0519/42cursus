/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 12:59:30 by junssong          #+#    #+#             */
/*   Updated: 2024/01/10 13:19:00 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <iostream>

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon) {

}

HumanA::~HumanA () {
}

void	HumanA::attack() {
// <name> attacks with their <weapon type>
    std::cout << _name
              << " attacks with their "
              << _weapon.getType() << std::endl;
}
