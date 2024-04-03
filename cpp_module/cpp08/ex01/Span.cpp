/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 18:47:26 by junssong          #+#    #+#             */
/*   Updated: 2024/04/03 11:08:14 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int n) :
	addSize(0),
	size(n),
	vec(new std::vector<int>)
{
	std::cout << "Span Constructor called." << std::endl;
}

Span::~Span()
{
	std::cout << "Span Destructor called." << std::endl;
	delete vec;
}

Span::Span(const Span& span) :
	vec(new std::vector<int>(0))
{
	std::cout << "Span Copy Constructor called." << std::endl;
	*this = span;
}

Span& Span::operator=(const Span& span)
{
	if (this == &span)
		return (*this);
	delete this->vec;
	this->vec = new std::vector<int>(span.vec->size());
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
	std::sort(this->vec->begin(), this->vec->end());
}

int	Span::shortestSpan()
{
	int span;

	if (this->addSize < 2)
		throw NoSpanException();
	for (unsigned int i = 0; i < this->vec->size() - 1; i++)
	{
		if (i == 0)
			span = this->vec->at(i + 1) - this->vec->at(i);
		else if (span > this->vec->at(i + 1) - this->vec->at(i))
		{
			int tmpSpan = this->vec->at(i + 1) - this->vec->at(i);
			if (span > tmpSpan)
				span = tmpSpan;
		}
	}
	return (span);
}

int	Span::longestSpan()
{
	if (this->addSize < 2)
		throw NoSpanException();
	return (this->vec->back() - this->vec->front());

}

const char* Span::SpanSizOverflowException::what() const throw()
{
	return "SpanSize overflow.";
}

const char* Span::NoSpanException::what() const throw()
{
	return "No Span.";
}
