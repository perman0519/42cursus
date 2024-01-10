/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 11:47:36 by junssong          #+#    #+#             */
/*   Updated: 2024/01/10 13:50:31 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Weapon {    
	public :
		Weapon(std::string type);
		~Weapon(void);
		
		std::string getType();
		void setType(std::string type);
		
	private :
		Weapon(void);
		std::string _type;

};