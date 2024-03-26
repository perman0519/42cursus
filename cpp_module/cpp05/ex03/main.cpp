/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:44:49 by junssong          #+#    #+#             */
/*   Updated: 2024/03/26 11:59:27 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "==test Intern==" << std::endl;
	{
		Bureaucrat *jun = new Bureaucrat("jun", 1);
		Intern *intern = new Intern();
		AForm *form = NULL;
		AForm *form2 = NULL;
		AForm *form3 = NULL;
		try
		{
			std::cout << std::endl;

			form = intern->makeForm("robotomy request", "Bender");
			jun->signForm(*form);
			jun->executeForm(*form);
			std::cout << std::endl;

			form2 = intern->makeForm("pre sidential pardon", "Bender");
			jun->signForm(*form2);
			jun->executeForm(*form2);
			std::cout << std::endl;

			form3 = intern->makeForm("shrubbery creation", "siuuuuu");
			jun->signForm(*form3);
			jun->executeForm(*form3);

			std::cout << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

		delete jun;
		delete intern;
		if (form)
			delete form;
		if (form2)
			delete form2;
		if (form3)
			delete form3;
	}
	return (0);
}
