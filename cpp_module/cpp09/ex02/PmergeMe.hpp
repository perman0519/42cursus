/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:16:16 by junssong          #+#    #+#             */
/*   Updated: 2024/04/17 19:14:57 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <sstream>
#include <exception>
#include <algorithm>
#include <cmath>

typedef std::vector<unsigned int>::iterator vecIt;
typedef std::vector<unsigned int> vecT;
typedef std::deque<unsigned int>::iterator dequeIt;
typedef std::deque<unsigned int> dequeT;

enum Container
{
	VECTOR,
	DEQUE
};

class PmergeMe
{
public:
	PmergeMe(char **argv);
	~PmergeMe();
	PmergeMe(const PmergeMe& copy);
	PmergeMe& operator=(const PmergeMe& obj);

	const vecT&	getVec() const;
	const dequeT&	getDeque() const;
	void	printVec(const vecT& vec) const;
	void	printDeque(const dequeT& deque) const;
	void	mergeInsertion(Container container);

	class InvalidInputException : public std::exception
	{
		const char* what() const throw();
	};

private:
	vecT	vec;
	dequeT	deque;

	void	insertionV(int bundle);
	void	comparePairV(int bundle);
	void	insertionD(int bundle);
	void	comparePairD(int bundle);
	void	helpMergeInsertionForVec(int layer);
	void	helpMergeInsertionForDeque(int layer);
};

