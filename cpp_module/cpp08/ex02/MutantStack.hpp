/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 16:24:28 by junssong          #+#    #+#             */
/*   Updated: 2024/04/03 17:26:12 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stack>


template <typename T>
class MutantStack : public std::stack<T>
{
public:
	MutantStack() : std::stack<T>() {}
	MutantStack(const MutantStack& stack) : std::stack<T>(stack) {}
	MutantStack& operator=(const MutantStack& stack)
	{
		if (this == &stack)
			return (*this);
		this->c = stack.c;
		return (*this);
	}
	~MutantStack() {}

	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator const_reverse_iterator;

	iterator	begin()
	{
		return (this->c.begin());
	}
	iterator	end()
	{
		return (this->c.end());
	}
	reverse_iterator	rbegin()
	{
		return (this->c.rbegin());
	}
	reverse_iterator	rend()
	{
		return (this->c.rend());
	}
	const const_iterator	cbegin()
	{
		return (this->c.cbegin());
	}
	const const_iterator	cend()
	{
		return (this->c.cend());
	}
	const const_reverse_iterator	crbegin()
	{
		return (this->c.crbegin());
	}
	const const_reverse_iterator	crend()
	{
		return (this->c.crend());
	}
};
