 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:27:20 by junssong          #+#    #+#             */
/*   Updated: 2024/01/08 14:09:31 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int	main()
{
	PhoneBook phoneBook;
	std::cout << "---------------------------------------------" << std::endl;
	while (true)
	{
		std::cout << "Please enter command : ";
		std::string cinStr;
		std::getline(std::cin, cinStr);
		if (cinStr.compare("ADD") == 0)
			phoneBook.add();
		else if  (cinStr.compare("SEARCH") == 0)
			phoneBook.search();
		else if  (cinStr.compare("EXIT") == 0)
			std::exit(0);
		else
		{
			std::cout << "Wrong command. Please try again." << std::endl;
			std::cout << "---------------------------------------------" << std::endl;
			std::cin.clear();
			clearerr(stdin);
		}
	}
}
