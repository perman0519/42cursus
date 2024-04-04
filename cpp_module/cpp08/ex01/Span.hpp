/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 18:36:07 by junssong          #+#    #+#             */
/*   Updated: 2024/04/04 12:25:05 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>

class Span
{
public:
	Span(unsigned int n);
	~Span();
	Span(const Span& span);
	Span& operator=(const Span& span);

	void	addNumber(int num);

	template <typename T>
	void	insert(T& var)
	{
		if (this->addSize + var.size() > this->size)
			throw SpanSizOverflowException();
		this->addSize += var.size();
		for (typename T::iterator it = var.begin(); it != var.end(); it++)
			this->vec->push_back(*it);
	}

	template <typename T>
	void	insert(const T& var)
	{
		if (this->addSize + var.size() > this->size)
			throw SpanSizOverflowException();
		this->addSize += var.size();
		for (typename T::const_iterator it = var.cbegin(); it != var.cend(); it++)
			this->vec->push_back(*it);
	}

	int		shortestSpan();
	int		longestSpan();

	class SpanSizOverflowException : public std::exception
	{
	public:
		const char* what() const throw();
	};

	class NoSpanException : public std::exception
	{
	public:
		const char* what() const throw();
	};

private:
	unsigned int		addSize;
	unsigned int		size;
	std::vector<unsigned int>	*vec;
};
