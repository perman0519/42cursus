/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:44:49 by junssong          #+#    #+#             */
/*   Updated: 2024/03/14 13:30:11 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
	std::cout << "==test ShrubberyCreationForm==" << std::endl;
	{
		try
		{
			Bureaucrat *bureaucrat = new Bureaucrat("junssong", 10);
			Bureaucrat *bureaucrat2 = new Bureaucrat("hee", 10);
			AForm *shrubbery = new ShrubberyCreationForm("shrubberyForm");
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

			delete bureaucrat;
			delete bureaucrat2;
			delete shrubbery;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			exit(1);
		}
	}
	std::cout << "==test2==" << std::endl;
	{
		try
		{
			Bureaucrat *bureaucrat = new Bureaucrat("junssong", 155);
			Bureaucrat *bureaucrat2 = new Bureaucrat("hee", 155);
			RobotomyRequestForm *robotomyRequestForm = new RobotomyRequestForm("robo");

			bureaucrat->signForm(*robotomyRequestForm);
			bureaucrat->executeForm(*robotomyRequestForm);

			delete bureaucrat;
			delete bureaucrat2;
			delete robotomyRequestForm;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
			exit(1);
		}

	}
	return (0);
}
