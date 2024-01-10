/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:04:58 by junssong          #+#    #+#             */
/*   Updated: 2024/01/10 10:59:26 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"
#include <iostream>

Zombie::Zombie( std::string name ) {
    this->_name = name;
}

Zombie::Zombie( void ) {
    std::cout << "Zombie maded" << std::endl;
}

Zombie::~Zombie( void ) {
    std::cout << this->_name << " : deleted" << std::endl;
}

void    Zombie::announce( void ) {
    std::cout << this->_name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::setName(std::string name) {
    this->_name = name;
}