/*
  Created by Junsang Song on 1/24/24.
*/

#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "Floor.hpp"

// void a() {
// 	system("leaks a.out");
// };

int main () {
	// atexit(a);
	Floor *floor = Floor::getInstance();
	{
		IMateriaSource *src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		AMateria *ice;
		AMateria *cure;
		ice = src->createMateria("ice");
		cure = src->createMateria("cure");
		Character me = Character("me");
		me.equip(ice);
		Character you = Character("you");
		you.equip(cure);

		me.use(0, you);
		you.use(0, me);
		std::cout << "==============================" << std::endl;
		me = you;
		me.use(0, you);
		you.use(0, me);

		me.unequip(0);
		you.unequip(0);

		delete src;
	}
	{
		IMateriaSource *src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		AMateria *ice;
		AMateria *cure;
		ice = src->createMateria("ice");
		cure = src->createMateria("cure");
		Character me = Character("me");
		me.equip(ice);
		me.equip(ice);
		Character you = Character("you");
		you.equip(cure);

		me.use(0, you);
		you.use(0, me);
		std::cout << "==============================" << std::endl;
		me = you;
		me.use(0, you);
		you.use(0, me);

		you.unequip(0);
		me.unequip(0);
		delete src;
	}
	delete floor;
	return 0;
}
