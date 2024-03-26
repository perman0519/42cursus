/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:53:31 by junssong          #+#    #+#             */
/*   Updated: 2024/03/26 11:52:16 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade) :
	name(name),
	grade(grade)
{
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	std::cout << "Bureaucrat Constructor" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat Destructor" <<std::endl;
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

void	Bureaucrat::signForm(AForm &form)
{
	if (this->grade < form.getSignGrade())
		std::cout << this->name << " signs " << form.getName() << std::endl;
	else
		std::cout << this->name << " cannot sign " << form.getName() << " because " << this->name << "'s grade is too low" << std::endl;
	form.beSigned(*this);
}

void	Bureaucrat::executeForm(AForm const &form)
{
	if (this->grade < form.getExecutionGrade())
		std::cout << this->name << " exectued " << form.getName() << std::endl;
	else
		std::cout << this->name << " cannot exectued " << form.getName() << " because " << this->name << "'s grade is too low" << std::endl;
	form.execute(*this);
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
