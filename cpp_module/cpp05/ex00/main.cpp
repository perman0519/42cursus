/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:44:49 by junssong          #+#    #+#             */
/*   Updated: 2024/03/06 20:45:08 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	//test1 : grade too high
	{
		try
		{
			Bureaucrat *bureaucrat = new Bureaucrat("jun", 0);
			delete bureaucrat;
		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	//test2 : success
	{
		try
		{
			Bureaucrat *bureaucrat = new Bureaucrat("jun", 1);
			std::cout << *bureaucrat << std::endl;
			delete bureaucrat;
		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}

	//test3 : grade too low
	{
		try
		{
			Bureaucrat *bureaucrat = new Bureaucrat("jun", 155);
			delete bureaucrat;
		}
		catch(std::exception &e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	return (0);
}
