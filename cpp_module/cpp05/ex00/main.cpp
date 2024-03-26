/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:44:49 by junssong          #+#    #+#             */
/*   Updated: 2024/03/26 14:50:59 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	//test1 : grade too high
	{
		std::cout << "==test1==" << std::endl;
		Bureaucrat *bureaucrat = NULL;
		try
		{
			bureaucrat = new Bureaucrat("jun", 0);
			delete bureaucrat;
			bureaucrat = NULL;
		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	//test2 : success
	{
		std::cout << "\n==test2==" << std::endl;
		Bureaucrat *bureaucrat;
		try
		{
			bureaucrat = new Bureaucrat("jun", 1);
			std::cout << *bureaucrat << std::endl;
			delete bureaucrat;
		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << std::endl;
			delete bureaucrat;
		}
	}

	//test3 : grade too low
	{
		std::cout << "\n==test3==" << std::endl;
		Bureaucrat *bureaucrat;
		try
		{
			bureaucrat = new Bureaucrat("jun", 155);
			delete bureaucrat;
		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return (0);
}
