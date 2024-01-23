/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:02:59 by junssong          #+#    #+#             */
/*   Updated: 2024/01/15 15:48:18 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP03_CLAPTRAP_HPP
#define CPP03_CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap {
public:
	ClapTrap(std::string name);

	ClapTrap(const ClapTrap &clapTrap);
	ClapTrap &operator=(const ClapTrap &clapTrap);
	~ClapTrap();

	void	attack(const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	std::string getName() const;
	unsigned int getEnergyPoints() const;
	unsigned int getHitPoints() const;
	unsigned int getAttackDamage() const;

private:
	ClapTrap();
	std::string _name;
	unsigned int _hitPoints;
	unsigned int _energyPoints;
	unsigned int _attackDamage;
};

#endif
