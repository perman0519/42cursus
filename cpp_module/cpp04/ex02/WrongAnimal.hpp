//
// Created by Junsang Song on 1/23/24.
//

#ifndef CPP04_WRONGANIMAL_HPP
#define CPP04_WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal {
public:
	WrongAnimal();
	virtual ~WrongAnimal();
	WrongAnimal(const WrongAnimal &WrongAnimal);
	WrongAnimal &operator=(const WrongAnimal &WrongAnimal);

	std::string getType() const;

	void makeSound() const ;

protected:
	std::string type;
};

#endif //CPP04_WRONGANIMAL_HPP
