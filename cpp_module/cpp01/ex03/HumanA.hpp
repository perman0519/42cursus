/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:48:05 by junssong          #+#    #+#             */
/*   Updated: 2024/01/10 12:59:10 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "./Weapon.hpp"

class HumanA {

public:
	HumanA(std::string name, Weapon &Weapon);
	~HumanA();
	void	attack();

private:
	HumanA();
	std::string	_name;
	Weapon		&_weapon;
};