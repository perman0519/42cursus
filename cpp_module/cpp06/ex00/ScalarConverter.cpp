/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:58:30 by junssong          #+#    #+#             */
/*   Updated: 2024/03/28 10:45:21 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter::Default constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter::Destructor called" << std::endl;
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
	int integer = std::atoi(str.c_str());
	float floating = static_cast<float>(std::atof(str.c_str()));
	double d = std::atof(str.c_str());
	char c = static_cast<char>(integer);

	std::cout << "char: ";
	if ((c >= 32 && c <= 126))
		std::cout << c;
	else
		std::cout << "Non displayable";
	std::cout << std::endl;
	std::cout << "int: ";

	// int integer = dynamic_cast<int>(str);
	// int integer = static_cast<int>(str);
	// int integer = reinterpret_cast<int>(str);
	// int integer = const_cast<int>(str);

}
