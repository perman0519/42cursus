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

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <cstdlib>
#include <cstdio>

int	main()
{
	PhoneBook phoneBook;
	std::cout << "---------------------------------------------" << std::endl;
	while (1)
	{
		std::cout << "Please enter command : ";
		std::string cin_str;
		std::getline(std::cin, cin_str);
		if (cin_str.compare("ADD") == 0)
			phoneBook.add();
		else if  (cin_str.compare("SEARCH") == 0)
			phoneBook.search();
		else if  (cin_str.compare("EXIT") == 0)
			std::exit(0);
		else
		{
			std::cout << "\nWrong command. Please try again." << std::endl;
			std::cout << "---------------------------------------------" << std::endl;
			std::cin.clear();
			clearerr(stdin);
			continue ;
		}
	}
}
