/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 21:10:36 by junssong          #+#    #+#             */
/*   Updated: 2024/01/15 12:59:57 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(Fixed(0)), _y(Fixed(0)) {
	 std::cout << "Default constructor called" << std::endl;
}

Point::Point(float const x, float const y) : _x(x), _y(y) {
	 std::cout << "float x, y constructor called" << std::endl;
}

Point::Point(const Point &point) : _x(point._x), _y(point._y) {
	 std::cout << "Copy constructor called" << std::endl;
}

Point& Point::operator=(const Point &point) {
	 std::cout << "Copy assignment operator called" << std::endl;
//	(Fixed)this->_x = point._x;
//	(Fixed)this->_y = point._y;
	const_cast<Fixed&>(this->_x) = point._x;
	const_cast<Fixed&>(this->_y) = point._x;
	return *this;
}

Point::~Point() {
	 std::cout << "Destructor called" << std::endl;
}

const Fixed	&Point::getX(void) const {
	return this->_x;
}

const Fixed	&Point::getY(void) const {
	return this->_y;
}