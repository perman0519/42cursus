/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:09:40 by junssong          #+#    #+#             */
/*   Updated: 2024/01/08 15:52:01 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H_
#define CONTACT_H_

#include <string>
#include <iostream>

class Contact {
public :
	Contact ();
	Contact (std::string firstname, std::string lastname, std::string nickname, std::string number, std::string darkestSecret);
	~Contact (void);

	std::string	getFirstname(void);
	std::string	getLastname(void);
	std::string getNickname(void);
	std::string getNumber(void);
	std::string	getDarkestSecret(void);

private :
	std::string	_firstName;
	std::string	_lastName;
	std::string	_nickname;
	std::string	_number;
	std::string	_darkestSecret;
};

#endif
