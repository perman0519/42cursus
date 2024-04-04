/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 19:08:24 by junssong          #+#    #+#             */
/*   Updated: 2024/04/04 11:53:58 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>
#include <array>

int main()
{
	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::srand(time(NULL));
	Span sp2 = Span(10000);
	try
	{
		std::vector<unsigned int> a(5000, 1);
		std::vector<unsigned int> b(5000, 100);
		sp2.insert(a);
		sp2.insert(b);

		// int *c = new int[5000];
		// for (int i = 0; i < 5000; i++)
		// 	c[i] = 1;
		// sp2.insert(c);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;
	return 0;
}
