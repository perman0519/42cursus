//
// Created by 송준상 on 1/28/24.
//

#ifndef CPP04_FLOOR_HPP
#define CPP04_FLOOR_HPP

#include "AMateria.hpp"
#include <iostream>

class Floor {
public:
	static void put(AMateria *unequipAMateria);
	static Floor *getInstance();
	~Floor();
	Floor(const Floor &floor);

private:
	Floor();
	Floor &operator=(const Floor &floor);

	static AMateria **list;

};


#endif //CPP04_FLOOR_HPP
