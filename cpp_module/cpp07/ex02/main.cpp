/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 18:36:29 by junssong          #+#    #+#             */
/*   Updated: 2024/04/01 12:38:48 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void)
{
	// Array<int> *int_arr = new Array<int>(5);
	// Array<float> *float_arr = new Array<float>(5);
	// Array<std::string> *string_arr = new Array<std::string>(5);

	// std::cout << "int_arr size: " << int_arr->getSize() << std::endl;
	// std::cout << "float_arr size: " << float_arr->getSize() << std::endl;
	// std::cout << "string_arr size: " << string_arr->getSize() << std::endl;

	// delete int_arr;
	// delete float_arr;
	// delete string_arr;
	int *a = new int[5];
	Array<int> int_arr(5);

	std::cout << a << std::endl;
	std::cout << &int_arr << std::endl;
	return (0);
}
