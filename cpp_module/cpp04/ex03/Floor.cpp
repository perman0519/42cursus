//
// Created by 송준상 on 1/28/24.
//

#include "Floor.hpp"

AMateria **Floor::list = new AMateria * [10];

void Floor::put(AMateria *unequipAMateria) {
	std::cout << "put unequip" << std::endl;
	size_t size = sizeof(list) / sizeof(AMateria);
	std::cout << "sizeof list : " << sizeof(*list) << std::endl;
	AMateria **tmp = new AMateria *[size + 1];
	for (size_t i = 0; i < size; ++i) {
		tmp[i] = Floor::list[i];
	}
	tmp[size] = unequipAMateria;
	delete[] Floor::list;
	Floor::list = tmp;
	size_t tmp_size = sizeof(tmp) / sizeof(AMateria);
	std::cout << "tmp_size : " << tmp_size << std::endl;
}

Floor::Floor() {}

Floor::~Floor() {
	std::cout << "delete unequip" << std::endl;
	size_t size = sizeof(list) / sizeof(AMateria *);
	std::cout << size << std::endl;
	for (size_t i = 0; i < size; ++i) {
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
