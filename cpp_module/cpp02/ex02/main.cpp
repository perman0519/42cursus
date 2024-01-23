/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:31:25 by junssong          #+#    #+#             */
/*   Updated: 2024/01/23 14:45:32 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main(void) {
    Fixed       a;
    Fixed const b(Fixed(5.05f) * Fixed(2.0f));
    Fixed const c(2.01f);

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;

    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    
    std::cout << b << std::endl;
    std::cout << 5.05f * 2 << std::endl;

    std::cout << Fixed::max(a, b) << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;

    std::cout << a - b << std::endl;
    std::cout << a * b << std::endl;

    std::cout << "b * c = " << a * c << std::endl;
    std::cout << "b * c = " << b * c << std::endl;
    
    return 0;
}