/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:55:44 by junssong          #+#    #+#             */
/*   Updated: 2024/01/11 16:40:15 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) {
     std::cout << "Copy constructor called" << std::endl;
    if (this != &fixed)
        this->_value = fixed.getRawBits();
}

Fixed::Fixed(const int integer) {
    std::cout << "Int constructor called" << std::endl;
    this->_value = integer << _fractionalBits;
}

Fixed::Fixed(const float number) {
    std::cout << "Float constructor called" << std::endl;
    float tmp = number * (1 << _fractionalBits);
    tmp = std::roundf(tmp);
    this->_value = tmp;
}

Fixed &Fixed::operator=(const Fixed &fixed) {
     std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed)
        this->_value = fixed.getRawBits();
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const {
    return this->_value;
}

void Fixed::setRawBits( int const raw ) {
    this->_value = raw;
}

float Fixed::toFloat() const {
    float a;
    a = (float)_value / 256;
    return a;
}

int Fixed::toInt() const {
    return _value >> 8;
}

std::ostream &operator<<(std::ostream& out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}