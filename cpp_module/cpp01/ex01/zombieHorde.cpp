/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:49:07 by junssong          #+#    #+#             */
/*   Updated: 2024/01/10 11:29:01 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.h"

Zombie* zombieHorde( int N, std::string name ) {
	Zombie *zombieArr = new Zombie[N];
	for (int i = 0; i < N; ++i) {
		zombieArr[i].setName(name);
	}
	return zombieArr;
}