/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:02:13 by junssong          #+#    #+#             */
/*   Updated: 2024/04/04 12:02:02 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main(void)
{
	std::vector<int> a;
	a.push_back(10);
	a.push_back(42);

	std::cout << *(easyfind(a, 10)) << std::endl;
	std::cout << *(easyfind(a, 42)) << std::endl;
	const std::vector<int> b(a);
	std::cout << *(easyfind(b, 10)) << std::endl;
	std::cout << *(easyfind(b, 42)) << std::endl;
	return (0);
}
