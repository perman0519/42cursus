//
// Created by Junsang Song on 1/23/24.
//

#ifndef CPP04_WRONGCAT_HPP
#define CPP04_WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
	WrongCat();
	~WrongCat();
	WrongCat(const WrongCat &WrongCat);
	WrongCat &operator=(const WrongCat &WrongCat);

	void makeSound() const ;

private:
};


#endif //CPP04_WRONGCAT_HPP
