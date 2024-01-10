#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {
}

Weapon::Weapon() {
}

Weapon::~Weapon() {
}

std::string Weapon::getType() {
    return _type;
}

void    Weapon::setType(std::string type) {
    this->_type = type;
}