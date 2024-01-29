//
// Created by Junsang Song on 1/23/24.
//

#ifndef CPP04_DOG_HPP
#define CPP04_DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
public:
	Dog();
    virtual ~Dog();
	Dog(const Dog &dog);
	Dog &operator=(const Dog &dog);

    virtual void makeSound() const ;

private:
	Brain *brain;
};

#endif //CPP04_DOG_HPP
