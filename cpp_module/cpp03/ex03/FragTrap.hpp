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

	void	highFivesGuys(void);

private:
	FragTrap();
};


#endif //CPP03_FRAGTRAP_HPP
