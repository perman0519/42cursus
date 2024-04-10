/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:15:34 by junssong          #+#    #+#             */
/*   Updated: 2024/04/10 12:06:33 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(char **argv) :
	_result(0)
{
	std::stringstream ss(argv[1]);
	std::string token;
	while (std::getline(ss, token, ' '))
	{
		if (token.length() == 1)
		{
			if (isdigit(token[0]))
			{
				this->_stack.push(token[0] - '0');
			}
			else
			{
				if (this->_stack.size() < 2)
					throw InvalidExpression();
				int a = this->_stack.top();
				this->_stack.pop();
				int b = this->_stack.top();
				this->_stack.pop();
				switch (token[0])
				{
				case '+':
					this->_stack.push(b + a);
					break;
				case '-':
					this->_stack.push(b - a);
					break;
				case '*':
					this->_stack.push(b * a);
					break;
				case '/':
					if (a == 0)
						throw InvalidExpression();
					this->_stack.push(b / a);
					break;
				default:
					throw InvalidExpression();
					break;
				}
			}
		}
		else
			throw InvalidExpression();
	}
}

RPN::~RPN()
{
}

RPN::RPN(const RPN& rpn)
{
	*this = rpn;
}

RPN& RPN::operator=(const RPN& rpn)
{
	if (this == &rpn)
		return *this;
	this->_stack = rpn._stack;
	this->_result = rpn._result;
	return *this;
}

const char *RPN::InvalidExpression::what() const throw()
{
	return "Error Invalid expression.";
}

int RPN::run()
{
	if (this->_stack.size() != 1)
		throw InvalidExpression();
	this->_result = this->_stack.top();
	return this->_result;
}
