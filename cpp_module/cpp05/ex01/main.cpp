/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:44:49 by junssong          #+#    #+#             */
/*   Updated: 2024/03/26 12:11:46 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout << "==test1==" << std::endl;
	{
		Bureaucrat *bureaucrat = NULL;
		Form *form = NULL;
		try
		{
			bureaucrat = new Bureaucrat("jun", 1);
			form = new Form("form1", 0, 140);
			delete bureaucrat;
			delete form;
			bureaucrat = NULL;
			form = NULL;
		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		if (bureaucrat)
			delete bureaucrat;
		if (form)
			delete form;
	}

	//test2 : success
	{
		std::cout << "==test2==" << std::endl;
		Bureaucrat	*bureaucrat = NULL;
		Form		*form = NULL;
		try
		{
			bureaucrat = new Bureaucrat("jun", 1);
			form = new Form("form1", 2, 3);
			bureaucrat->signForm(*form);
			std::cout << *bureaucrat << std::endl;
			std::cout << *form << std::endl;
			delete bureaucrat;
			delete form;
			bureaucrat = NULL;
			form = NULL;
		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		if (bureaucrat)
			delete bureaucrat;
		if (form)
			delete form;
	}

	//test3 : grade too low
	{
		std::cout << "==test3==" << std::endl;
		Bureaucrat	*bureaucrat = NULL;
		Form		*form = NULL;
		try
		{
			bureaucrat = new Bureaucrat("jun", 144);
			form = new Form("form1", 2, 300);
			form->beSigned(*bureaucrat);
			delete bureaucrat;
			bureaucrat = NULL;
			delete form;
			form = NULL;
		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
		if (bureaucrat)
			delete bureaucrat;
		if (form)
			delete form;
	}
	return (0);
}
