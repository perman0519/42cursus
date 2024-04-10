/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:15:39 by junssong          #+#    #+#             */
/*   Updated: 2024/04/09 15:16:43 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stack>
#include <sstream>
#include <exception>

class RPN
{
public:
	RPN(char **argv);
	~RPN();
	RPN(const RPN& rpn);
	RPN& operator=(const RPN& rpn);

	int	run();

	class InvalidExpression : public std::exception
	{
		const char* what() const throw();
	};

private:
	std::stack<int>	_stack;
	int				_result;
};
