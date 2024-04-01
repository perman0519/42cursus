/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 18:36:27 by junssong          #+#    #+#             */
/*   Updated: 2024/03/30 23:40:38 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void print(int const &i)
{
	std::cout << i << std::endl;
}

void print(float const &f)
{
	std::cout << f << std::endl;
}

void print(std::string const &s)
{
	std::cout << s << std::endl;
}

int main(void)
{
	int int_array[5] = {1, 2, 3, 4, 5};
	float float_array[5] = {1.1, 2.2, 3.3, 4.4, 5.5};
	std::string string_array[5] = {"one", "two", "three", "four", "five"};

	std::cout << "int_array: ";
	iter(int_array, 5, print);
	std::cout << "float_array: ";
	iter(float_array, 5, print);
	std::cout << "string_array: ";
	iter(string_array, 5, print);
	return (0);
}
