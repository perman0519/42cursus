/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:03:02 by junssong          #+#    #+#             */
/*   Updated: 2024/01/15 14:03:05 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main() {
	ScavTrap scavTrap1(std::string("scavTrap1"));
	ScavTrap scavTrap2 = scavTrap1;

	scavTrap1.guardGate();

	scavTrap1.attack("enemy");

	scavTrap2.attack("powder");

	std::cout << scavTrap1.getName() << std::endl;
	std::cout << scavTrap2.getName() << std::endl;

	return 0;
}
