/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:16:14 by junssong          #+#    #+#             */
/*   Updated: 2024/04/18 19:55:53 by junssong         ###   ########.fr       */
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
		this->vec.push_back(num);
		this->deque.push_back(num);
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
	this->deque = obj.deque;
	return (*this);
}

const vecT&	PmergeMe::getVec() const
{
	return this->vec;
}

const dequeT&	PmergeMe::getDeque() const
{
	return this->deque;
}

void PmergeMe::printVec(const vecT& vec) const
{
    vecT::const_iterator it = vec.begin();
    vecT::const_iterator end = vec.end();
    for (; it != end; ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void PmergeMe::printDeque(const dequeT& deque) const
{
    dequeT::const_iterator it = deque.begin();
    dequeT::const_iterator end = deque.end();
    for (; it != end; ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}
const char* PmergeMe::InvalidInputException::what() const throw()
{
	return ("Error: Invalid Input.");
}

void	PmergeMe::comparePairV(int bundle)
{
	for (size_t i = 0; i + bundle * 2 <= this->vec.size(); i += bundle * 2)
	{
		if (this->vec[i] < this->vec[i + bundle])
		{
			for (int j = 0; j < bundle; j++)
			{
				int tmp = this->vec[i + j + bundle];
				this->vec[i + j + bundle] = this->vec[i + j];
				this->vec[i + j] = tmp;
			}
		}
	}
}

void	PmergeMe::comparePairD(int bundle)
{
	for (size_t i = 0; i + bundle * 2 <= this->deque.size(); i += bundle * 2)
	{
		if (this->deque[i] < this->deque[i + bundle])
		{
			for (int j = 0; j < bundle; j++)
			{
				int tmp = this->deque[i + j + bundle];
				this->deque[i + j + bundle] = this->deque[i + j];
				this->deque[i + j] = tmp;
			}
		}
	}
}

void	PmergeMe::mergeInsertion(Container container)
{
	if (container == VECTOR)
		helpMergeInsertionForVec(0);
	else if (container == DEQUE)
		helpMergeInsertionForDeque(0);
}

void	PmergeMe::helpMergeInsertionForVec(int layer)
{
	int bundle = std::pow(2, layer);
	if (std::pow(2, layer + 1) > this->vec.size())
		return;
	this->comparePairV(bundle);
	this->helpMergeInsertionForVec(++layer);
	this->insertionV(bundle);
}

void	PmergeMe::helpMergeInsertionForDeque(int layer)
{
	int bundle = std::pow(2, layer);
	if (std::pow(2, layer + 1) > this->deque.size())
		return;
	this->comparePairD(bundle);
	this->helpMergeInsertionForDeque(++layer);
	this->insertionD(bundle);
}

int getJacobsthal(int idx, int prevJacob, int nextJacob)
{
	if (idx - 1 == prevJacob)
	{
		return (nextJacob + (2 * prevJacob));
	}
	else
	{
		return (idx - 1);
	}
}

int atBinarySearchV(int nowB, vecT& main, int right, int bundle)
{
	int left = 0;
	int middle = (left + right) / 2;
	while (left <= right)
	{
		int middleNum = main.at(middle * bundle);
		if (nowB < middleNum)
		{
			right = middle - 1;
			middle = (left + right) / 2;
		}
		else
		{
			left = middle + 1;
			middle = (left + right) / 2;
		}
	}
	return left;
}

int atBinarySearchD(int nowB, dequeT& main, int right, int bundle)
{
	int left = 0;
	int middle = (left + right) / 2;
	while (left <= right)
	{
		int middleNum = main.at(middle * bundle);
		if (nowB < middleNum)
		{
			right = middle - 1;
			middle = (left + right) / 2;
		}
		else
		{
			left = middle + 1;
			middle = (left + right) / 2;
		}
	}
	return left;
}

void	PmergeMe::insertionV(int bundle)
{
	vecT main;
	vecT pending;
	vecIt it = this->vec.begin();
	int i = 0;

	while (it + (i + 2) * bundle <= this->vec.end())
	{
		main.insert(main.end(), it + (i * bundle), it + (i + 1) * bundle);
		pending.insert(pending.end(), it + (i + 1) * bundle, it + (i + 2) * bundle);
		i += 2;
	}
	if (it + (i + 1) * bundle <= this->vec.end())
		pending.insert(pending.end(), it + i * bundle, it + (i + 1) * bundle);
	main.insert(main.begin(), pending.begin(), pending.begin() + bundle);

	int prevJacob = 1;
	int nextJacob = 3;
	int idx = 3;
	int penSize = pending.size() - bundle;
	while (penSize > 0)
	{
		if ((idx - 1) * bundle < static_cast<int>(pending.size()))
		{
			int nowB = pending.at((idx - 1) * bundle);
			int right = prevJacob * 2 + (nextJacob - prevJacob - 1) - 1;
			if (right * bundle >= static_cast<int>(main.size()))
				right = main.size() / bundle - 1;
			int insertMainIdx = atBinarySearchV(nowB, main, right, bundle);
			main.insert(main.begin() + insertMainIdx * bundle, pending.begin() + (idx - 1) * bundle, pending.begin() + idx * bundle);
			penSize -= bundle;
		}
		idx = getJacobsthal(idx, prevJacob, nextJacob);
		if (idx > nextJacob)
		{
			prevJacob = nextJacob;
			nextJacob = idx;
		}
	}
	i = 0;
	for (it = main.begin(); it != main.end(); it++)
	{
		this->vec[i] = main[i];
		i++;
	}
}

void	PmergeMe::insertionD(int bundle)
{
	dequeT main;
	dequeT pending;
	dequeIt it = this->deque.begin();
	int i = 0;

	while (it + (i + 2) * bundle <= this->deque.end())
	{
		main.insert(main.end(), it + (i * bundle), it + (i + 1) * bundle);
		pending.insert(pending.end(), it + (i + 1) * bundle, it + (i + 2) * bundle);
		i += 2;
	}
	if (it + (i + 1) * bundle <= this->deque.end())
		pending.insert(pending.end(), it + i * bundle, it + (i + 1) * bundle);
	main.insert(main.begin(), pending.begin(), pending.begin() + bundle);

	int prevJacob = 1;
	int nextJacob = 3;
	int idx = 3;
	int penSize = pending.size() - bundle;
	while (penSize > 0)
	{
		if ((idx - 1) * bundle < static_cast<int>(pending.size()))
		{
			int nowB = pending.at((idx - 1) * bundle);
			int right = prevJacob * 2 + (nextJacob - prevJacob - 1) - 1;
			if (right * bundle >= static_cast<int>(main.size()))
				right = main.size() / bundle - 1;
			int insertMainIdx = atBinarySearchD(nowB, main, right, bundle);
			main.insert(main.begin() + insertMainIdx * bundle, pending.begin() + (idx - 1) * bundle, pending.begin() + idx * bundle);
			penSize -= bundle;
		}
		idx = getJacobsthal(idx, prevJacob, nextJacob);
		if (idx > nextJacob)
		{
			prevJacob = nextJacob;
			nextJacob = idx;
		}
	}
	i = 0;
	for (it = main.begin(); it != main.end(); it++)
	{
		this->deque[i] = main[i];
		i++;
	}
}
