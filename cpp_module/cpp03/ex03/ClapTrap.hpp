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
	virtual ~ClapTrap();
	ClapTrap(const ClapTrap &clapTrap);
	ClapTrap &operator=(const ClapTrap &clapTrap);

	virtual void	attack(const std::string &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	const std::string &getName() const;
	const unsigned int &getEnergyPoints() const;
	const unsigned int &getHitPoints() const;
	const unsigned int &getAttackDamage() const;

protected:
	ClapTrap();
	std::string _name;
	unsigned int _energyPoints;
	unsigned int _hitPoints;    
	unsigned int _attackDamage;
};

#endif //CPP03_CLAPTRAP_HPP