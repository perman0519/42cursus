/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:16:14 by junssong          #+#    #+#             */
/*   Updated: 2024/04/12 20:36:53 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **argv)
{
	std::string argvs;
	for (int i = 1; argv[i]; i++)
	{
		argvs = std::string(argv[i]);
		if (argvs.find_first_not_of("0123456789") != std::string::npos)
			throw InvalidInputException();
		unsigned int num = std::atoi(argv[i]);
		if (num < 0)
			throw InvalidInputException();
		this->vec.push_back(num);
	}
}

PmergeMe::~PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe& copy)
{
	*this = copy;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& obj)
{
	this->vec = obj.vec;
	this->pending = obj.pending;
	return (*this);
}

void PmergeMe::printVec(std::vector<unsigned int> vec)
{
	for (vecIt it = vec.begin(); it != vec.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

const char* PmergeMe::InvalidInputException::what() const throw()
{
	return ("Error: Invalid Input.");
}

void	PmergeMe::comparePair(int bundle)
{
	// std::cout << "bundle: " << bundle << std::endl;
	vecIt it = this->vec.begin();
	while (it + bundle < this->vec.end())
	{
		if (*it < *(it + bundle))
		{
			std::vector<unsigned int> tmp;
			tmp.insert(tmp.begin(), it + bundle, it + bundle * 2);
			this->vec.insert(it, tmp.begin(), tmp.end());
			this->vec.erase(it + bundle * 2, it + bundle * 3);
		}
		it += bundle * 2;
	}
	this->printVec(this->vec);
}

void	PmergeMe::insertion(int bundle)
{
	vecIt it = this->vec.begin();
	vecT main;
	vecT pending;
	vecIt mainIt = main.begin();
	vecIt pendingIt = pending.begin();

	int i = 0;
	while (it + bundle < this->vec.end())
	{
		main.insert(mainIt + i, it, it + bundle);
		pending.insert(pendingIt + i, it + bundle, it + bundle * 2);
		it += bundle * 2;
		i += bundle;
	}
	std::cout << "bundle : " << bundle << std::endl;
	this->printVec(this->vec);
	std::cout << "main: " << main.size() << " : ";
	this->printVec(main);
	std::cout << "pending: " << pending.size() << " : ";
	this->printVec(pending);


	// while (pending.size() == 0)
	// {
	// 	int pendingtmp = pending.at((nowJacobsthal - 1) * bundle);
	// 	int maintmp = main.at((nowJacobsthal - 1) * bundle);
	// }
}

void	PmergeMe::mergeInsertion(int layer)
{
	int bundle = std::pow(2, layer);
	if (std::pow(2, layer + 1) > this->vec.size())
		return;
	std::cout << "layer: " << layer << std::endl;

	this->comparePair(bundle);
	mergeInsertion(++layer);
	insertion(bundle);
}
