/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 21:10:43 by junssong          #+#    #+#             */
/*   Updated: 2024/01/15 12:37:43 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP
#include <iostream>
#include "Fixed.hpp"

class Point {
public:
	Point();
	Point(const Point &point);
	Point &operator=(const Point &fixed);
	~Point();
	Point(float const x, float const y);
	const Fixed	&getX(void) const;
	const Fixed	&getY(void) const;


private:
	Fixed const _x;
	Fixed const _y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif //CPP02_POINT_HPP
