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
#include <cstdlib>

Zombie* zombieHorde( int N, std::string name ) {
	Zombie *zombieArr = new Zombie[N];
	for (int i = 0; i < N; ++i) {
		std::string iStr;          // string which will contain the result
		std::ostringstream convert;   // stream used for the conversion
		convert << i;      // insert the textual representation of 'Number' in the characters in the stream
		iStr = convert.str(); // set 'Result' to the contents of the stream
		zombieArr[i].setName(name + iStr);
	}
	return zombieArr;
}