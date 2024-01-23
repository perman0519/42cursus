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

#include "ClapTrap.hpp"

int main() {
	ClapTrap clapTrap1(std::string("clapTrap1"));
	ClapTrap clapTrap2(std::string("clapTrap2"));
	ClapTrap clapTrap3 = clapTrap2;

	clapTrap1.attack(clapTrap2.getName());
	clapTrap2.takeDamage(clapTrap1.getAttackDamage());
	std::cout << clapTrap2.getHitPoints() << std::endl;
	std::cout << clapTrap3.getHitPoints() << std::endl;
	clapTrap2.beRepaired(10);
	std::cout << clapTrap2.getHitPoints() << std::endl;
	std::cout << clapTrap3.getHitPoints() << std::endl;
}
