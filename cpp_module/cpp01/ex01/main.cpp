/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:13:22 by junssong          #+#    #+#             */
/*   Updated: 2024/01/10 11:28:43 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"
#include "./Zombie.h"

int main()
{
    std::string name("zombie");
    Zombie *zombies = zombieHorde(10, name);
    for (int i = 0; i < 10; ++i) {
        zombies[i].announce();
    }
    delete [] zombies;
    return 0;
}