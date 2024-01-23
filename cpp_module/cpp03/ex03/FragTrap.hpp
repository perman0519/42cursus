//
// Created by Junsang Song on 1/15/24.
//

#ifndef CPP03_FRAGTRAP_HPP
#define CPP03_FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {
public:
	FragTrap(std::string name);

	~FragTrap();
	FragTrap(const FragTrap &fragTrap);
	FragTrap &operator=(const FragTrap &fragTrap);

	void	highFivesGuys(void);

protected:
	FragTrap();
};


#endif //CPP03_FRAGTRAP_HPP
