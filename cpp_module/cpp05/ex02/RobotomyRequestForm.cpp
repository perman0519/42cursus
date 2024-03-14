/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 21:22:35 by junssong          #+#    #+#             */
/*   Updated: 2024/03/14 13:25:32 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &name) :
	AForm(name, 72, 45)
{
	std::cout << "RobotomyRequestForm Constructor" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Destructor" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) :
	AForm(other.getName(), other.getSignGrade(), other.getExecutionGrade())
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
	if (this->getSign() == false)
		throw SignedFailedException();
	if (executor.getGrade() > this->getExecutionGrade())
		throw GradeTooLowException();
	std::cout << "DDDDddddd..." << std::endl;
	std::srand(std::time(0));
	if (std::rand() % 2)
		std::cout << "success!!" << std::endl;
	else
		std::cout << "failed.." << std::endl;

}

const char *	RobotomyRequestForm::SignedFailedException::what() const throw()
{
	return ("RobotomyRequestForm is not signed.");
}
