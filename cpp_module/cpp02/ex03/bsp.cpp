/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 03:06:31 by junssong          #+#    #+#             */
/*   Updated: 2024/01/15 13:26:34 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

float sign (Point p1, Point p2, Point p3)
{
	Fixed x1 = p1.getX();
	Fixed y1 = p1.getY();
	Fixed x2 = p2.getX();
	Fixed y2 = p2.getY();
	Fixed x3 = p3.getX();
	Fixed y3 = p3.getY();
	return ((x1 * y2 + x2 * y3 + x3 * y1) - (y1 * x2 + y2 * x3 + y3 * x1)).toFloat();
}

bool checkVector(const float a, const float b) {
	if (a > 0 && b > 0)
		return true;
	if (a < 0 && b < 0)
		return true;
	return false;
}

float vecDir(Point &m, Point &n) {
	return ((m.getX() * n.getY()) - (m.getY() * n.getX())).toFloat();
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {
//	float d1, d2, d3;
//    bool has_neg, has_pos;
//
//	d1 = sign(a, b, point);
//    d2 = sign(b, c, point);
//    d3 = sign(c, a, point);
//
//    has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
//    has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);
//
//	return !(has_neg && has_pos);
	 Point vec_ab((b.getX() - a.getX()).toFloat(), (b.getY() - a.getY()).toFloat());
	 Point vec_bc((c.getX() - b.getX()).toFloat(), (c.getY() - b.getY()).toFloat());
	 Point vec_ca((a.getX() - c.getX()).toFloat(), (a.getY() - c.getY()).toFloat());
	 Point vec_ap((point.getX() - a.getX()).toFloat(), (point.getY() - a.getY()).toFloat());
	 Point vec_bp((point.getX() - b.getX()).toFloat(), (point.getY() - b.getY()).toFloat());
	 Point vec_cp((point.getX() - c.getX()).toFloat(), (point.getY() - c.getY()).toFloat());

	 if (!checkVector(vecDir(vec_ab, vec_bc), vecDir(vec_ab, vec_ap)))
		 return false;
	 if (!checkVector(vecDir(vec_bc, vec_ca), vecDir(vec_bc, vec_bp)))
		 return false;
	 if (!checkVector(vecDir(vec_ca, vec_ab), vecDir(vec_ca, vec_cp)))
		 return false;
	return true;
}