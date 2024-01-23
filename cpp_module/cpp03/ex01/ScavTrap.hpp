/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:54:00 by junssong          #+#    #+#             */
/*   Updated: 2024/01/15 15:54:04 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP03_SCAVTRAP_HPP
#define CPP03_SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {
public:
	ScavTrap(std::string name);
	
	~ScavTrap();
	ScavTrap(const ScavTrap &scavTrap);
	ScavTrap &operator=(const ScavTrap &scavTrap);

	void	guardGate();
	void	attack(const std::string &target);

private:
	ScavTrap();
};


#endif //CPP03_SCAVTRAP_HPP
