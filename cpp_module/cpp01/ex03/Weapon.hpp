/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:47:36 by junssong          #+#    #+#             */
/*   Updated: 2024/01/10 12:02:38 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Weapon {    
	public :
		Weapon(std::string type);
		~Weapon(void);
		std::string getType();
		std::string setType();
		
	private :
		Weapon(void);
		std::string _type;

};