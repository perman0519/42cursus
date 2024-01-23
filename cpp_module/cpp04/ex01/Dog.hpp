//
// Created by Junsang Song on 1/23/24.
//

#ifndef CPP04_DOG_HPP
#define CPP04_DOG_HPP

#include "Animal.hpp"

class Dog : public Animal {
public:
	Dog();
	~Dog();
	Dog(const Dog &dog);
	Dog &operator=(const Dog &dog);

	void makeSound() const ;
};

#endif //CPP04_DOG_HPP
