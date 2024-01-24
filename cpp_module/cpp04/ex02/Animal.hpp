//
// Created by Junsang Song on 1/23/24.
//

#ifndef CPP04_ANIMAL_HPP
#define CPP04_ANIMAL_HPP

#include <string>
#include <iostream>

class Animal {
public:
	Animal();
	virtual ~Animal();
	Animal(const Animal &animal);
	Animal &operator=(const Animal &animal);

	std::string getType() const;

	virtual void makeSound() const = 0;

protected:
	std::string type;
};

#endif //CPP04_ANIMAL_HPP
