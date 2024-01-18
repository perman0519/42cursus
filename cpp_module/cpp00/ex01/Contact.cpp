/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:09:34 by junssong          #+#    #+#             */
/*   Updated: 2024/01/08 15:51:27 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

Contact::Contact (std::string firstName, std::string lastName, std::string nickName, std::string number, std::string darkestSecret) : _firstName(firstName), _lastName(lastName), _nickname(nickName), _number(number), _darkestSecret(darkestSecret) {}

//getter
std::string	Contact::getFirstname(void) {
	return this->_firstName;
}

std::string	Contact::getLastname(void) {
	return this->_lastName;
}

std::string Contact::getNickname(void) {
	return this->_nickname;
}

std::string	Contact::getNumber(void) {
	return this->_number;
}

std::string	Contact::getDarkestSecret(void) {
	return this->_darkestSecret;
}
