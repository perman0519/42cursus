/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:55:52 by junssong          #+#    #+#             */
/*   Updated: 2024/01/11 16:40:03 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
public:
    Fixed();
    Fixed(const int integer);
    Fixed(const float number);
    Fixed(const Fixed &fixed);
    ~Fixed();

    Fixed &operator=(const Fixed &fixed);

	int getRawBits( void ) const;
    void setRawBits( int const raw );
    float toFloat( void ) const;
    int toInt( void ) const;

    bool operator>(const Fixed &fixed);
    bool operator<(const Fixed &fixed);
    bool operator>=(const Fixed &fixed);
    bool operator<=(const Fixed &fixed);
    bool operator==(const Fixed &fixed);
    bool operator!=(const Fixed &fixed);

    Fixed operator+(const Fixed &fixed);
    Fixed operator-(const Fixed &fixed);
    Fixed operator*(const Fixed &fixed);
    Fixed operator/(const Fixed &fixed);

    Fixed &operator++();
    Fixed operator++(int);
    Fixed &operator--();
    Fixed operator--(int);

    static Fixed& min(Fixed &fixed1, Fixed &fixed2);
    static const Fixed& min(const Fixed &fixed1, const Fixed &fixed2);
    static Fixed& max(Fixed &fixed1, Fixed &fixed2);
    static const Fixed& max(const Fixed &fixed1, const Fixed &fixed2);

private:
    int _value;
    static const int _fractionalBits = 8;
};

std::ostream &operator<<(std::ostream& out, const Fixed &fixed);

#endif //FIXED_HPP
