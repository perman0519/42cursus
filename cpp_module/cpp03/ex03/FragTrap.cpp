#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    this->_name = name;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	this->_hitPoints = 100;
	std::cout << "FragTrap: " << this->_name << " Constructor called" << std::endl;
}

FragTrap::FragTrap() {}

FragTrap::FragTrap(const FragTrap &fragTrap) {
	std::cout << "FragTrap: Copy constructor called" << std::endl;
	*this = fragTrap;
}

FragTrap &FragTrap::operator=(const FragTrap &fragTrap) {
	std::cout << "FragTrap: Copy assignment operator called" << std::endl;
	if (this != &fragTrap) {
		this->_name = fragTrap._name;
		this->_hitPoints = fragTrap._hitPoints;
		this->_energyPoints = fragTrap._energyPoints;
		this->_attackDamage = fragTrap._attackDamage;
	}
	return *this;
}

FragTrap::~FragTrap() {
	std::cout <<  "FragTrap: " << this->_name << " Destructor called" << std::endl;
}

void	FragTrap::highFivesGuys(void) {
	std::cout << "HighFives FiveGuys~!" << std::endl;
}

#include "FragTrap.hpp"
