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

int main() {
	ClapTrap *clapTrap1 = new ScavTrap(std::string("scavTrap1"));
	FragTrap fragTrap1("fragTrap1");

	clapTrap1->attack("enemy");

	fragTrap1.highFivesGuys();

	std::cout << clapTrap1->getName() << std::endl;
	std::cout << fragTrap1.getName() << std::endl;

	delete(clapTrap1);
}
