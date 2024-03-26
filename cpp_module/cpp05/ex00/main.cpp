/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:44:49 by junssong          #+#    #+#             */
/*   Updated: 2024/03/26 12:09:08 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	//test1 : grade too high
	{
		Bureaucrat *bureaucrat;
		try
		{
			bureaucrat = new Bureaucrat("jun", 0);
			delete bureaucrat;
		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << std::endl;
			delete bureaucrat;
		}
	}

	//test2 : success
	{
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
		Bureaucrat *bureaucrat;
		try
		{
			bureaucrat = new Bureaucrat("jun", 155);
			delete bureaucrat;
		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << std::endl;
			delete bureaucrat;
		}
	}
	return (0);
}
