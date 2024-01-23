/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 21:10:43 by junssong          #+#    #+#             */
/*   Updated: 2024/01/23 13:31:35 by junssong         ###   ########.fr       */
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
	Fixed	&getX(void) const;
	Fixed	&getY(void) const;

private:
	Fixed const _x;
	Fixed const _y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
