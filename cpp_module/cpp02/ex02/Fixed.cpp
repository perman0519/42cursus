/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:55:44 by junssong          #+#    #+#             */
/*   Updated: 2024/01/23 14:47:23 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
    // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &fixed) {
    //  std::cout << "Copy constructor called" << std::endl;
    if (this != &fixed)
        this->_value = fixed.getRawBits();
}

Fixed::Fixed(const int integer) {
    // std::cout << "Int constructor called" << std::endl;
    this->_value = integer << _fractionalBits;
}

Fixed::Fixed(const float number) {
    // std::cout << "Float constructor called" << std::endl;
    float tmp = number * (1 << _fractionalBits);
    tmp = roundf(tmp);
    this->_value = tmp;
}

Fixed& Fixed::operator=(const Fixed &fixed) {
    //  std::cout << "Copy assignment operator called" << std::endl;
    if (this != &fixed)
        this->_value = fixed.getRawBits();
    return *this;
}

Fixed::~Fixed() {
    // std::cout << "Destructor called" << std::endl;
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

std::ostream& operator<<(std::ostream& out, const Fixed &fixed) {
    out << fixed.toFloat();
    return out;
}

bool Fixed::operator>(const Fixed &fixed) {
    return this->toFloat() > fixed.toFloat();
}

bool Fixed::operator<(const Fixed &fixed) {
    return this->toFloat() < fixed.toFloat();
}

bool Fixed::operator>=(const Fixed &fixed) {
    return this->toFloat() >= fixed.toFloat();
}

bool Fixed::operator<=(const Fixed &fixed) {
    return this->toFloat() <= fixed.toFloat();
}

bool Fixed::operator==(const Fixed &fixed) {
    return this->toFloat() == fixed.toFloat();
}

bool Fixed::operator!=(const Fixed &fixed) {
    return this->toFloat() != fixed.toFloat();
}

Fixed Fixed::operator+(const Fixed &fixed) {
    return Fixed(this->toFloat() + fixed.toFloat());
}

Fixed Fixed::operator-(const Fixed &fixed) {
    return Fixed(this->toFloat() - fixed.toFloat());
}

Fixed Fixed::operator*(const Fixed &fixed) const {
    return Fixed (this->toFloat() * fixed.toFloat());
}

Fixed Fixed::operator/(const Fixed &fixed) {
    return Fixed(this->toFloat() / fixed.toFloat());
}

Fixed &Fixed::operator++() {
    ++this->_value;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp(*this);
    ++this->_value;
    return temp;
}

Fixed &Fixed::operator--() {
    --this->_value;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp(*this);
    --this->_value;
    return temp;
}

Fixed& Fixed::min(Fixed &fixed1, Fixed &fixed2) {
    return fixed1.toFloat() > fixed2.toFloat() ? fixed2 : fixed1;
}

const Fixed& Fixed::min(const Fixed &fixed1, const Fixed &fixed2) {
    return fixed1.toFloat() > fixed2.toFloat() ? fixed2 : fixed1;
}

Fixed& Fixed::max(Fixed &fixed1, Fixed &fixed2) {
    return fixed1.toFloat() > fixed2.toFloat() ? fixed1 : fixed2;
}

const Fixed& Fixed::max(const Fixed &fixed1, const Fixed &fixed2) {
    return fixed1.toFloat() > fixed2.toFloat() ? fixed1 : fixed2;
}