/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:13:55 by junssong          #+#    #+#             */
/*   Updated: 2024/04/11 18:41:48 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error." << std::endl;
		return (1);
	}
	try
	{
		PmergeMe pmm(argv);
		std::cout << "Original: ";
		// pmm.printVec();
		pmm.mergeInsertion(0);
		std::cout << "Sorted: ";
		// pmm.printVec();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
