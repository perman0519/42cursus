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
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
    ScavTrap *scavTrap = new ScavTrap("asdf");
    FragTrap *fragTrap = new FragTrap("asdfasdfasdf");
    DiamondTrap *diamondTrap1 = new DiamondTrap("diamond1");
    std::cout << "attackDamage: " << diamondTrap1->getAttackDamage() << std::endl
            << "getEnergyPoints: " << diamondTrap1->getEnergyPoints() << std::endl
            << "getHitPoints: " << diamondTrap1->getHitPoints() << std::endl;

    diamondTrap1->attack("asdf");

    diamondTrap1->whoAmI();

	DiamondTrap diamondTrap2("hello world");
	DiamondTrap diamondTrap3 = diamondTrap2;

	diamondTrap2.whoAmI();

	std::cout << diamondTrap2.getHitPoints() << std::endl;
	std::cout << diamondTrap3.getHitPoints() << std::endl;
	diamondTrap2.beRepaired(100);
	std::cout << diamondTrap2.getHitPoints() << std::endl;
	std::cout << diamondTrap3.getHitPoints() << std::endl;

    delete(scavTrap);
    delete(fragTrap);
	delete(diamondTrap1);
}
