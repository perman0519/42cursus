/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:02:51 by junssong          #+#    #+#             */
/*   Updated: 2024/03/09 20:11:50 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string &name, const int signGrade, const int executionGrade) :
	name(name),
	signGrade(signGrade),
	executionGrade(executionGrade)
{
	if (signGrade > 150 || executionGrade > 150)
		throw GradeTooLowException();
	else if (signGrade < 1 || executionGrade < 1)
		throw GradeTooHighException();
	this->sign = false;
	std::cout << "Form Constructor" << std::endl;
}

Form::~Form()
{
	std::cout  << "Form Destructor" << std::endl;
}

Form::Form(const Form &form) :
	signGrade(form.signGrade),
	executionGrade(form.executionGrade)
{
	*this = form;
}

Form &Form::operator=(const Form &form)
{
	if (this != &form)
		this->sign = form.sign;
	return (*this);
}

int Form::getSignGrade() const
{
	return (this->signGrade);
}

int Form::getExecutionGrade() const
{
	return (this->executionGrade);
}

bool Form::getSign() const
{
	return (this->sign);
}

std::string &Form::getName() const
{
	return (const_cast<std::string &>(this->name));
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->signGrade)
		throw GradeTooLowException();
	this->sign = true;
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << "Form: " << form.getName() << ", sign grade: " << form.getSignGrade() << ", execution grade: " << form.getExecutionGrade() << ", sign status: " << form.getSign() << ".";
	return (out);
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return "Form::Grade is too high";
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return "Form::Grade is too low";
}
