/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 21:22:35 by junssong          #+#    #+#             */
/*   Updated: 2024/03/26 15:44:21 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) :
	AForm("ShrubberyCreationForm", 145, 137),
	_target(target)
{
	std::cout << "ShrubberyCreationForm Constructor" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Destructor" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) :
	AForm(other.getName(), other.getSignGrade(), other.getExecutionGrade()),
	_target(other._target)
{
	std::cout << "ShrubberyCreationForm Copy constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	std::cout << "ShrubberyCreationForm Copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	*((AForm *)(this)) = *((AForm *)(&other));
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	check_sign();
	check_executionGrade(executor);
	std::string fileName = std::string(this->_target + "_shrubbery");
	std::ofstream ofs(fileName.c_str(), std::ios_base::out);
	for (size_t i = 1; i < 10; i++)
	{
		for (size_t j = 0; j < 10 - i; j++)
		{
			ofs << " ";
		}
		for (size_t j = 0; j < 2 * i - 1; j++)
		{
			ofs << "*";
		}
		ofs << "\n";
	}
}
