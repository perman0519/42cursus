/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:48:05 by junssong          #+#    #+#             */
/*   Updated: 2024/01/10 12:01:27 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "./Weapon.hpp"

class HumanA {

public:
void	attack();

private:
	std::string	_name;
	Weapon		_weapon;
};