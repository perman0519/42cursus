//
// Created by Junsang Song on 1/24/24.
//

#include "AMateria.hpp"
#include "MateriaSource.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"

void a() {
	system("leaks a.out");
};

int main () {
	atexit(a);
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

//		me.unequip(0);
		you.unequip(0);
		delete cure;
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
		Character you = Character("you");
		you.equip(cure);

		me.use(0, you);
		you.use(0, me);
		std::cout << "==============================" << std::endl;
		me = you;
		me.use(0, you);
		you.use(0, me);

//		me.unequip(0);
		you.unequip(0);
		delete cure;
		delete src;
	}



//	{
//		IMateriaSource *src = new MateriaSource();
//		src->learnMateria(new Ice());
//		src->learnMateria(new Cure());
//		ICharacter *me = new Character("me");
//		AMateria *ice;
//		AMateria *cure;
//
//		ice = src->createMateria("ice");
//		me->equip(ice);
//		cure = src->createMateria("cure");
//		me->equip(cure);
//		me->unequip(1);
//		delete cure;
//		ICharacter *bob = new Character("bob");
//		me->use(0, *bob);
//		me->use(1, *bob);
//		ICharacter *you = me;
//
//		std::cout << &me << std::endl;
//		std::cout << &you << std::endl;
//		std::cout << &me << std::endl;
//		std::cout << &you << std::endl;
//
//		you->use(0, *me);
//		delete bob;
//		delete me;
//		delete src;
//	}
//	{
//		IMateriaSource *src = new MateriaSource();
//		src->learnMateria(new Ice());
//		src->learnMateria(new Cure());
//		Character me = Character("me");
//
//		Character you = Character(me);
//		AMateria *tmp;
//		tmp = src->createMateria("ice");
//		me.equip(tmp);
////		ICharacter *bob = new Character("bob");
//		me.use(0, me);
//		me.unequip(0);
//		delete tmp;
//		delete src;
//
//	}

	return 0;
}
