/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:53:31 by junssong          #+#    #+#             */
/*   Updated: 2024/03/09 12:01:07 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name)
{
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	else
		this->grade = grade;
	std::cout << green << "Bureaucrat Constructor" << reset << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << red << "Bureaucrat Destructor" << reset <<std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)
{
	*this = bureaucrat;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
	if (this != &bureaucrat)
		this->grade = bureaucrat.grade;
	return (*this);
}

std::string &Bureaucrat::getName() const
{
	return (const_cast<std::string &>(this->name));
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (out);
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Bureaucrat::Grade is too high";
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Bureaucrat::Grade is too low";
}
