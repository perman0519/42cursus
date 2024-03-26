/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 11:53:31 by junssong          #+#    #+#             */
/*   Updated: 2024/03/26 15:41:32 by junssong         ###   ########.fr       */
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
	try
	{
		form.beSigned(*this);
	}
	catch (std::exception &e)
	{
		std::cout << *this << " cannot sign " << form << " because " << e.what() << std::endl;
		return ;
	}
	std::cout << *this << " signed " << form << "." << std::endl;
}

void	Bureaucrat::executeForm(AForm const &form)
{
	try
	{
		form.execute(*this);
	}
	catch(const std::exception& e)
	{
		std::cout << *this << " cannot exectued " << form.getName()
			<< " because " << e.what() << std::endl;
		return ;
	}
	std::cout << *this << " executed " << form << "." << std::endl;
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << "bureaucrat name: " << bureaucrat.getName()
		<< ", bureaucrat grade: " << bureaucrat.getGrade();
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
