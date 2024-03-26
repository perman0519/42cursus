/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 20:55:38 by junssong          #+#    #+#             */
/*   Updated: 2024/03/26 11:54:03 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
	std::cout << "Intern Constructor" << std::endl;
}

Intern::~Intern()
{
	std::cout << "Intern Destructor" << std::endl;
}

Intern::Intern(const Intern &intern)
{
	std::cout << "Intern Copy constructor called" << std::endl;
	*this = intern;
}

Intern &Intern::operator=(const Intern &intern)
{
	std::cout << "Intern Copy assignment operator called" << std::endl;
	if (this == &intern)
		return (*this);
	return (*this);
}

AForm *	Intern::robotomy(const std::string& target)
{
	AForm*	form = new RobotomyRequestForm(target);
	return (form);
}

AForm *	Intern::presidential(const std::string& target)
{
	AForm*	form = new PresidentialPardonForm(target);
	return (form);
}

AForm *	Intern::shrubbery(const std::string& target)
{
	AForm*	form = new ShrubberyCreationForm(target);
	return (form);
}

AForm*	Intern::makeForm(const std::string &name, const std::string &target)
{
	AForm*		form = NULL;
	std::string	formName[3] = {"robotomy request", "presidential pardon", "shrubbery creation"};
	AForm*		(Intern::*f[3])(const std::string& target) = {&Intern::robotomy, &Intern::presidential, &Intern::shrubbery};
	int			level_i = -1;


	for (int i = 0; i < 4; ++i) {
		if (formName[i] == name) {
			level_i = i;
			break;
		}
	}
	switch (level_i) {
		case 0:
			form = (this->*f[level_i])(target);
			break;
		case 1:
			form = (this->*f[level_i])(target);
			break;
		case 2:
			form = (this->*f[level_i])(target);
			break;
		default:
			throw FormNotFoundException();
			break;
	}
	return (form);
}

const char *Intern::FormNotFoundException::what() const throw()
{
	return ("Form not found");
}
