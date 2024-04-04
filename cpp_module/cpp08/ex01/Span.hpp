/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 18:36:07 by junssong          #+#    #+#             */
/*   Updated: 2024/04/04 10:38:32 by junssong         ###   ########.fr       */
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
	void	insert(std::vector<unsigned int>& var);
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
