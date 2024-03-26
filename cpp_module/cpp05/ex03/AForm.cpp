/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:02:51 by junssong          #+#    #+#             */
/*   Updated: 2024/03/26 15:40:23 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string &name, const int signGrade, const int executionGrade) :
	name(name),
	signGrade(signGrade),
	executionGrade(executionGrade)
{
	if (signGrade > 150 || executionGrade > 150)
		throw GradeTooLowException();
	else if (signGrade < 1 || executionGrade < 1)
		throw GradeTooHighException();
	this->sign = false;
	std::cout << "AForm Constructor" << std::endl;
}

AForm::~AForm()
{
	std::cout  << "AForm Destructor" << std::endl;
}

AForm::AForm(const AForm &form) :
	signGrade(form.signGrade),
	executionGrade(form.executionGrade)
{
	*this = form;
	std::cout << "AForm Copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &form)
{
	if (this != &form)
		this->sign = form.sign;
	std::cout << "AForm Copy assignment operator called" << std::endl;
	// const_cast<std::string &>(this->name) = form.name;
	this->sign = form.sign;
	return (*this);
}

int AForm::getSignGrade() const
{
	return (this->signGrade);
}

int AForm::getExecutionGrade() const
{
	return (this->executionGrade);
}

bool AForm::getSign() const
{
	return (this->sign);
}

std::string &AForm::getName() const
{
	return (const_cast<std::string &>(this->name));
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (this->signGrade < bureaucrat.getGrade())
		throw GradeTooLowException();
	this->sign = true;
}

void AForm::check_executionGrade(Bureaucrat const &bureaucrat) const
{
	if (bureaucrat.getGrade() > this->executionGrade)
		throw GradeTooLowException();
}

void AForm::check_sign() const
{
	if (this->sign == false)
		throw SignedFailedException();
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
	out << "AForm name: " << form.getName()
		<< ", sign grade: " << form.getSignGrade()
		<< ", execution grade: " << form.getExecutionGrade()
		<< ", sign status: " << std::boolalpha << form.getSign() << std::noboolalpha;
	return (out);
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return "AForm::Grade is too high";
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return "AForm::Grade is too low";
}

const char *	AForm::SignedFailedException::what() const throw()
{
	return ("AForm::Form is not signed.");
}
