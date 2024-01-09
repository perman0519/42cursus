/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 16:13:22 by junssong          #+#    #+#             */
/*   Updated: 2024/01/08 16:41:16 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Zombie.hpp"
#include "./Zombie.h"

int main()
{
    std::string name("zombie1");
    Zombie *zombie = newZombie(name);
    zombie->announce();
    randomChump(std::string("zombie2"));
    zombie->~Zombie();
    // delete zombie;
    //2개 다 됨.
    return 0;
}