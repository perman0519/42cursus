//
// Created by Junsang Song on 1/24/24.
//

int main () {
	IMateriaSource *src = newMateriaSource();
	src->learnMateria(newIce());
	src->learnMateria(newCure());
	ICharacter *me = newCharacter("me");
	AMateria *tmp;

	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter *bob = newCharacter("bob");
	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	return 0;
}
