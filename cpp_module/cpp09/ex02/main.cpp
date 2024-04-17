/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:13:55 by junssong          #+#    #+#             */
/*   Updated: 2024/04/17 19:52:50 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <ctime>

int main(int argc, char **argv)
{
	if (argc < 2)
	{
		std::cerr << "Error." << std::endl;
		return (1);
	}
	try
	{
		clock_t start, finish;
		PmergeMe pmm(argv);
		std::cout << "Vector BeFore: ";
		pmm.printVec(pmm.getVec());
		start = std::clock();
		pmm.mergeInsertion(VECTOR);
		finish = std::clock();
		std::cout << "Vector After:  ";
		pmm.printVec(pmm.getVec());
		std::cout << "Time to process a range of "<< pmm.getVec().size() << " elements with std::vector : " <<  (double)(finish - start) / CLOCKS_PER_SEC * 1000000 << " us" << std::endl;

		std::cout << "Deque BeFore:  ";
		pmm.printDeque(pmm.getDeque());
		start = std::clock();
		pmm.mergeInsertion(DEQUE);
		finish = std::clock();
		std::cout << "Deque After:   ";
		pmm.printDeque(pmm.getDeque());
		std::cout << "Time to process a range of "<< pmm.getDeque().size() << " elements with std::deque : " << (double)(finish - start) / CLOCKS_PER_SEC * 1000000 << " us" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << '\n';
	}
	return (0);
}
