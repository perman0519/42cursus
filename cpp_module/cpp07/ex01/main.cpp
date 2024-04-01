/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 18:36:27 by junssong          #+#    #+#             */
/*   Updated: 2024/04/01 11:50:35 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void print(T &x)
{
	std::cout << x << std::endl;
}

template <typename T>
void print2(const T &x)
{
	std::cout << (x + x) << std::endl;
}

int main(void)
{
	int int_array[5] = {1, 2, 3, 4, 5};
	float float_array[5] = {1.1f, 2.24234f, 3.32344234f, 4.4234f, 5.5555555f};
	std::string string_array[5] = {"one", "two", "three", "four", "five"};

	const int int_array2[5] = {1, 2, 3, 4, 5};
	const float float_array2[5] = {1.1f, 2.24234f, 3.32344234f, 4.4234f, 5.5555555f};
	const std::string string_array2[5] = {"one", "two", "three", "four", "five"};

	iter(int_array, 5, print);
	iter(float_array, 5, print);
	iter(string_array, 5, print);

	iter(int_array2, 5, print2);
	iter(float_array2, 5, print2);
	iter(string_array2, 5, print2);
	return (0);
}
