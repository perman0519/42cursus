/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:44:49 by junssong          #+#    #+#             */
/*   Updated: 2024/03/26 12:07:33 by junssong         ###   ########.fr       */
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
		Bureaucrat *bureaucrat = new Bureaucrat("junssong", 10);
		Bureaucrat *bureaucrat2 = new Bureaucrat("hee", 10);
		AForm *shrubbery = new ShrubberyCreationForm("shrubberyForm");
		try
		{
			bureaucrat->signForm(*shrubbery);
			shrubbery->execute(*bureaucrat);

			ShrubberyCreationForm a("lee");
			ShrubberyCreationForm b(a);
			ShrubberyCreationForm c("jun");
			c = a;

			std::cout << b.getName() << b.getSignGrade() << std::endl;
			std::cout << c.getName() << c.getSignGrade() << std::endl;
			bureaucrat->signForm(b);
			b.execute(*bureaucrat2);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			delete bureaucrat;
			delete bureaucrat2;
			delete shrubbery;
			exit(1);
		}
		delete bureaucrat;
		delete bureaucrat2;
		delete shrubbery;
	}
	std::cout << "==RobotomyRequestForm==" << std::endl;
	{
		Bureaucrat *bureaucrat = new Bureaucrat("junssong", 1);
		RobotomyRequestForm *robotomyRequestForm = new RobotomyRequestForm("robo");
		try
		{
			bureaucrat->signForm(*robotomyRequestForm);
			for(int count = 0; count < 1000; count++)
			{
				bureaucrat->executeForm(*robotomyRequestForm);
			}
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			delete(bureaucrat);
			delete(robotomyRequestForm);
			exit(1);
		}
		delete(bureaucrat);
		delete(robotomyRequestForm);
	}
	std::cout << "==PresidentialPardonForm==" << std::endl;
	{
		Bureaucrat *bureaucrat = new Bureaucrat("junssong", 1);
		PresidentialPardonForm *presidentialPardonForm = new PresidentialPardonForm("presidentialPardonForm");
		try
		{
			bureaucrat->signForm(*presidentialPardonForm);
			bureaucrat->executeForm(*presidentialPardonForm);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			delete bureaucrat;
			delete presidentialPardonForm;
			exit(1);
		}
		delete bureaucrat;
		delete presidentialPardonForm;
	}
	return (0);
}
