/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:04:46 by junssong          #+#    #+#             */
/*   Updated: 2024/01/10 10:56:00 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class Zombie {

public :
	~Zombie( void );
	Zombie ( void );
	Zombie(std::string name);
	void	setName(std::string name);
	void	announce( void );

private :
	
	std::string _name;
	

};