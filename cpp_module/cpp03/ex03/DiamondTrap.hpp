/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 15:24:25 by junssong          #+#    #+#             */
/*   Updated: 2024/01/16 15:24:25 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPP03_DIAMONDTRAP_HPP
#define CPP03_DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap {
public:
    DiamondTrap(std::string name);
    DiamondTrap(const DiamondTrap &diamondTrap);
    ~DiamondTrap();
    DiamondTrap &operator=(const DiamondTrap &diamondTrap);
    void whoAmI();
private:
    DiamondTrap();
    std::string name;
};


#endif //CPP03_DIAMONDTRAP_HPP
