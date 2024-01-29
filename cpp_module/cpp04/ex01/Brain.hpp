//
// Created by Junsang Song on 1/23/24.
//

#ifndef CPP04_BRAIN_HPP
#define CPP04_BRAIN_HPP

#include <string>
#include <iostream>

class Brain {
public:
	Brain();
	~Brain();
	Brain(const Brain &brain);
	Brain &operator=(const Brain &brain);

	const std::string *getIdeas() const;

private:
	std::string ideas[100];
};

#endif //CPP04_BRAIN_HPP
