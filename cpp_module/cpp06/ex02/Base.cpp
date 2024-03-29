/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 11:19:49 by junssong          #+#    #+#             */
/*   Updated: 2024/03/29 13:11:31 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
	std::cout << "Base Destructor called." << std::endl;
}

Base*	generate(void)
{
	int random = std::rand() % 3;

	if (random == 0)
	{
		std::cout << "A is generated." << std::endl;
		return (new A);
	}
	else if (random == 1)
	{
		std::cout << "B is generated." << std::endl;
		return (new B);
	}
	else
	{
		std::cout << "C is generated." << std::endl;
		return (new C);
	}
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A is identified." << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B is identified." << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C is identified." << std::endl;
}

void	identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A is identified." << std::endl;
	}
	catch(const std::exception& e)
	{
		try
		{
			B& b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "B is identified." << std::endl;
		}
		catch(const std::exception& e)
		{
			try
			{
				C& c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << "C is identified." << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cout << "Error: Not identified." << std::endl;
			}
		}
	}
}
