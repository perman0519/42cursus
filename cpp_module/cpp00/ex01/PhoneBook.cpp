/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:09:08 by junssong          #+#    #+#             */
/*   Updated: 2024/01/08 15:51:33 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {
	contactCount = 0;
	contactIndex = 0;
	std::cout << "*PhoneBook*" << std::endl;
}

PhoneBook::~PhoneBook() {
	std::cout << "PhoneBook deleted." << std::endl;
}

void	PhoneBook::add() {
	if (contactCount < 8)
	{
		std::string firstName, lastName, nickName, number, secret;
		std::cout << "firstName : ";
		std::getline(std::cin, firstName);
		if (checkEmpty(firstName))
			return ;
		std::cout << "lastName  : ";
		std::getline(std::cin, lastName);
		if (checkEmpty(lastName))
			return ;
		std::cout << "nickname  : ";
		std::getline(std::cin, nickName);
		if (checkEmpty(nickName))
			return ;
		std::cout << "number    : ";
		std::getline(std::cin, number);
		if (checkEmpty(number))
			return ;
		if (std::atoi(number.c_str()) == 0)
		{
			std::cout << "wrong number. try again." << std::endl;
			return ;
		}
		std::cout << "secret    : ";
		std::getline(std::cin, secret);
		if (checkEmpty(secret))
			return ;
		Contact newContact (firstName, lastName, nickName, std::atoi(number.c_str()), secret);
		this->contactArr[this->contactIndex] = newContact;
		this->contactIndex++;
		this->contactCount++;
	}
	else
	{
		this->contactIndex %= 8;
		std::string firstName, lastName, nickName, number, secret;
		std::cout << "firstName : ";
		std::getline(std::cin, firstName);
		if (checkEmpty(firstName))
			return ;
		std::cout << "lastName  : ";
		std::getline(std::cin, lastName);
		if (checkEmpty(lastName))
			return ;
		std::cout << "nickname  : ";
		std::getline(std::cin, nickName);
		if (checkEmpty(nickName))
			return ;
		std::cout << "number    : ";
		std::getline(std::cin, number);
		if (checkEmpty(number))
			return ;
		if (std::atoi(number.c_str()) == 0)
		{
			std::cout << "wrong number. try again." << std::endl;
			return ;
		}
		std::cout << "secret    : ";
		std::getline(std::cin, secret);
		if (checkEmpty(secret))
			return ;
		Contact newContact (firstName, lastName, nickName, std::atoi(number.c_str()), secret);
		this->contactArr[this->contactIndex] = newContact;
		this->contactIndex++;
	}
}

void	PhoneBook::search() {
	std::string	searchIndex;
	std::cout << "Choose index : ";
	std::getline(std::cin, searchIndex);
	int searchIndexInt = std::atoi(searchIndex.c_str());
	if (!(searchIndexInt > 0 && searchIndexInt <= this->contactCount))
	{
		std::cout << "wrong index. try again." << std::endl;
		return ;
	}
	std::cout << "---------------------------------------------\n";
	std::cout << "|     index| firstName|  lastName|  nickname|\n";
	std::cout << "---------------------------------------------" << std::endl;
	for (int i = 0; i < this->contactCount; i++)
	{
		coutSearch(i + 1);
		coutSearch(this->contactArr[i].getFirstname());
		coutSearch(this->contactArr[i].getLastname());
		coutSearch(this->contactArr[i].getNickname());
		std::cout << "|" << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
	}
}

void	PhoneBook::coutSearch(std::string str) {
	std::cout << "|";
	if (str.size() > 10)
	{
		std::cout << std::setw(9) << std::right;
		str = str.substr(0, 9);
		std::cout << str << ".";
	}
	else
	{
		std::cout << std::setw(10) << std::right;
		std::cout << str.substr(0, 10);
	}
}

void	PhoneBook::coutSearch(int num) {
	std::cout << "|";
	std::cout << std::setw(10) << std::right;
	std::cout << num;
}

int	PhoneBook::checkEmpty(std::string str) {
	if (str.empty())
	{
		std::cout << "wrong input. try again." << std::endl;
		return (1);
	}
	else
	{
		for (int i = 0; i < (int)str.size(); i++)
		{
			if (isspace(str[i]))
			{
				std::cout << "wrong input. try again." << std::endl;
				return (1);
			}
		}
	}
		return (0);
}