/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 21:22:35 by junssong          #+#    #+#             */
/*   Updated: 2024/03/26 15:45:06 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) :
	AForm("RobotomyRequestForm", 72, 45),
	_target(target)
{
	std::cout << "RobotomyRequestForm Constructor" << std::endl;
	std::srand(std::time(NULL));
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Destructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) :
	AForm(other.getName(), other.getSignGrade(), other.getExecutionGrade()),
	_target(other._target)
{
	std::cout << "RobotomyRequestForm Copy constructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	std::cout << "RobotomyRequestForm Copy assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	*((AForm *)(this)) = *((AForm *)(&other));
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	check_sign();
	check_executionGrade(executor);
	std::cout << "DDDDddddd..." << std::endl;
	std::cout << this->_target;
	if (std::rand() % 2)
		std::cout << " success!!" << std::endl;
	else
		std::cout << " failed.." << std::endl;
}
