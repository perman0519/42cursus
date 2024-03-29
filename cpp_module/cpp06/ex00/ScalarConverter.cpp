/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:58:30 by junssong          #+#    #+#             */
/*   Updated: 2024/03/28 20:27:34 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	// std::cout << "ScalarConverter::Default constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	// std::cout << "ScalarConverter::Destructor called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
	std::cout << "ScalarConverter::Copy constructor called" << std::endl;
	*this = copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& obj)
{
	std::cout << "ScalarConverter::Assignation operator called" << std::endl;
	if (this == &obj)
		return (*this);
	return (*this);
}

void	ScalarConverter::convert(std::string str)
{
	char *end_str = NULL;
	double d = strtod(str.c_str(), &end_str);
	float f = static_cast<float>(d);
	std::string end_string(end_str);
	std::cout << "end_str: " << end_string << std::endl;


	std::cout << "char:   ";
	if (end_string.length() == 0)
	{
		if (str.find('.') != std::string::npos)
			std::cout << "impossible" << std::endl;
		else if (d >= 0 && d <= 31)
			std::cout << "Non displayable" << std::endl;
		else if (d >= 32 && d <= 127)
			std::cout << "'" << static_cast<char>(d) << "'" << std::endl;
		else
			std::cout << "impossible" << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;

	std::cout << "int:    ";
	if (end_string.length() == 0)
	{
		if (str.find('.') == std::string::npos && str != "+inf" && str != "-inf" && str != "nan")
			std::cout << std::atoi(str.c_str()) << std::endl;
		else
			std::cout << "impossible" << std::endl;
	}
	else
		std::cout << "impossible" << std::endl;


	std::cout << "float:  ";
	if (end_string.length() == 0)
	{
		if (str.find('.') == std::string::npos && str != "+inf" && str != "-inf" && str != "nan" && f != INFINITY && f != -INFINITY && f != NAN)
			std::cout << f << ".0f" << std::endl;
		else
			std::cout << f << "f" << std::endl;
	}
	else
	{
		if (end_string == "f")
			std::cout << f << "f" << std::endl;
		else
			std::cout << "impossible" << std::endl;
	}

	std::cout << "double: ";
	if (end_string.length() == 0)
	{
		if (str.find('.') == std::string::npos && str != "+inf" && str != "-inf" && str != "nan"&& str != "nan" && d != INFINITY && d != -INFINITY && d != NAN)
			std::cout << d << ".0" << std::endl;
		else
			std::cout << d << std::endl;
	}
	else
	{
		if (end_string == "f")
		{
			if (str.find('.') == std::string::npos)
				std::cout << d << ".0" << std::endl;
			else
				std::cout << d << std::endl;
		}
		else
			std::cout << "impossible" << std::endl;
	}
}
