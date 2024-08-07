/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:48:15 by junssong          #+#    #+#             */
/*   Updated: 2024/01/10 13:05:17 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "./Weapon.hpp"

class HumanB {

public:
	HumanB(std::string name);
	~HumanB();
	
	void	setWeapon(Weapon &weapon);
	void	attack();

private:
	HumanB();
	std::string	_name;
	Weapon		*_weapon;
};