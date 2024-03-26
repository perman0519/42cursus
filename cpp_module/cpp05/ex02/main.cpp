/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:44:49 by junssong          #+#    #+#             */
/*   Updated: 2024/03/26 15:39:00 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	std::cout << "==test ShrubberyCreationForm==" << std::endl;
	{
		Bureaucrat *bureaucrat = new Bureaucrat("junssong", 150);
		Bureaucrat *bureaucrat2 = new Bureaucrat("hee", 10);
		AForm *shrubbery = new ShrubberyCreationForm("home");
		std::cout << std::endl;

		// bureaucrat->signForm(*shrubbery);
		bureaucrat2->signForm(*shrubbery);
		// bureaucrat->executeForm(*shrubbery);
		bureaucrat2->executeForm(*shrubbery);
		std::cout << std::endl;

		delete bureaucrat;
		delete bureaucrat2;
		delete shrubbery;
	}
	std::cout << "\n==RobotomyRequestForm==" << std::endl;
	{
		Bureaucrat *bureaucrat = new Bureaucrat("junssong", 1);
		RobotomyRequestForm *robotomyRequestForm = new RobotomyRequestForm("robo");
		std::cout << std::endl;

		bureaucrat->signForm(*robotomyRequestForm);
		for(int count = 0; count < 2; count++)
		{
			bureaucrat->executeForm(*robotomyRequestForm);
		}
		std::cout << std::endl;

		delete(bureaucrat);
		delete(robotomyRequestForm);
	}
	std::cout << "\n==PresidentialPardonForm==" << std::endl;
	{
		Bureaucrat *bureaucrat = new Bureaucrat("junssong", 20);
		PresidentialPardonForm *presidentialPardonForm = new PresidentialPardonForm("presidentialPardonForm");
		std::cout << std::endl;

		bureaucrat->signForm(*presidentialPardonForm);
		bureaucrat->executeForm(*presidentialPardonForm);
		std::cout << std::endl;

		delete bureaucrat;
		delete presidentialPardonForm;
	}
	return (0);
}
