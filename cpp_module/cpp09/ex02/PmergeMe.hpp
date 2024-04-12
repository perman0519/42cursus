/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:16:16 by junssong          #+#    #+#             */
/*   Updated: 2024/04/12 20:20:25 by junssong         ###   ########.fr       */
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

class PmergeMe
{
public:
	PmergeMe(char **argv);
	~PmergeMe();
	PmergeMe(const PmergeMe& copy);
	PmergeMe& operator=(const PmergeMe& obj);

	class InvalidInputException : public std::exception
	{
		const char* what() const throw();
	};

	void	printVec(std::vector<unsigned int> vec);
	void	mergeInsertion(int layer);

private:
	void	merge();
	void	insertion(int bundle);
	void	comparePair(int bundle);

	std::vector<unsigned int>	vec;
	std::vector<unsigned int>	main;
	std::deque<unsigned int>	pending;
};

