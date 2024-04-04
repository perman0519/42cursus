/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 18:47:26 by junssong          #+#    #+#             */
/*   Updated: 2024/04/04 12:22:28 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) :
	addSize(0),
	size(n),
	vec(new std::vector<unsigned int>)
{
	std::cout << "Span Constructor called." << std::endl;
}

Span::~Span()
{
	std::cout << "Span Destructor called." << std::endl;
	delete vec;
}

Span::Span(const Span& span) :
	vec(new std::vector<unsigned int>)
{
	std::cout << "Span Copy Constructor called." << std::endl;
	*this = span;
}

Span& Span::operator=(const Span& span)
{
	if (this == &span)
		return (*this);
	delete this->vec;
	this->vec = new std::vector<unsigned int>(span.vec->size());
	std::copy(span.vec->begin(), span.vec->end(), this->vec->begin());
	this->addSize = span.addSize;
	this->size = span.size;
	return (*this);
}

void	Span::addNumber(int num)
{
	if (this->addSize == this->size)
		throw SpanSizOverflowException();
	this->addSize++;
	this->vec->push_back(num);
}

int	Span::shortestSpan()
{
	int span = 2147483647;

	std::sort(this->vec->begin(), this->vec->end());
	if (this->addSize < 2)
		throw NoSpanException();
	for (std::vector<unsigned int>::iterator it = this->vec->begin(); it != this->vec->end(); it++)
	{
		if (it == this->vec->begin())
			continue;
		int tmpSpan = *(it) - *(it - 1);
		if (tmpSpan < span)
			span = tmpSpan;
	}
	return (span);
}

int	Span::longestSpan()
{
	if (this->addSize < 2)
		throw NoSpanException();
	int a = *max_element(this->vec->begin(), this->vec->end());
	int b = *min_element(this->vec->begin(), this->vec->end());
	return (a - b);
}

const char* Span::SpanSizOverflowException::what() const throw()
{
	return "SpanSize overflow.";
}

const char* Span::NoSpanException::what() const throw()
{
	return "No Span.";
}
