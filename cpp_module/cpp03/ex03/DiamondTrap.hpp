/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:24:25 by junssong          #+#    #+#             */
/*   Updated: 2024/03/26 12:17:24 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP03_DIAMONDTRAP_HPP
#define CPP03_DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
public:
	DiamondTrap(std::string name);
	~DiamondTrap();
	DiamondTrap(const DiamondTrap &diamondTrap);
	DiamondTrap &operator=(const DiamondTrap &diamondTrap);

	void whoAmI();

private:
	std::string _name;
};

#endif //CPP03_DIAMONDTRAP_HPP
