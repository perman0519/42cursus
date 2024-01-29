//
// Created by 송준상 on 1/28/24.
//

#include "Floor.hpp"

AMateria **Floor::list = new AMateria * [0];
int Floor::size = 0;

void Floor::put(AMateria *unequipAMateria) {
	AMateria **tmp = new AMateria *[size + 1];
	for (int i = 0; i < Floor::size; ++i) {
		tmp[i] = Floor::list[i];
	}
	tmp[size] = unequipAMateria;
	Floor::size += 1;
	delete[] Floor::list;
	Floor::list = tmp;
}

Floor::Floor() {}

Floor::~Floor() {
	for (int i = 0; i < Floor::size; ++i) {
		delete Floor::list[i];
	}
	delete [] list;
}

Floor::Floor(const Floor &floor) {
	*this = floor;
}

Floor &Floor::operator=(const Floor &floor) {
	if (this == &floor)
		return *this;
	return *this;
}

Floor *Floor::getInstance() {
	static Floor *floor = new Floor;
	Floor::list[0] = NULL;
	return floor;
}
