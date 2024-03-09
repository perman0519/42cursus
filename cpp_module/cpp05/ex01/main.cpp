/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:44:49 by junssong          #+#    #+#             */
/*   Updated: 2024/03/09 20:35:49 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout << "==test1==" << std::endl;
	{
		try
		{
			Bureaucrat *bureaucrat = new Bureaucrat("jun", 1);
			Form *form = new Form("form1", 0, 140);
			delete bureaucrat;
			delete form;
		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	//test2 : success
	{
		std::cout << "==test2==" << std::endl;
		try
		{
			Bureaucrat *bureaucrat = new Bureaucrat("jun", 1);
			Form *form = new Form("form1", 2, 3);
			bureaucrat->signForm(*form);
			std::cout << *bureaucrat << std::endl;
			std::cout << *form << std::endl;
			delete bureaucrat;
			delete form;
		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	//test3 : grade too low
	{
		std::cout << "==test3==" << std::endl;
		try
		{
			Bureaucrat *bureaucrat = new Bureaucrat("jun", 144);
			Form *form = new Form("form1", 2, 300);
			form->beSigned(*bureaucrat);
			delete bureaucrat;
		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return (0);
}
