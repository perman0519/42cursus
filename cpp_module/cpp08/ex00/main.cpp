/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:02:13 by junssong          #+#    #+#             */
/*   Updated: 2024/04/01 18:43:28 by junssong         ###   ########.fr       */
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
	std::cout << *(easyfind(a, 0)) << std::endl;
	return (0);
}
