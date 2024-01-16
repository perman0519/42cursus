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

#ifndef _CONTACT_H_
#define _CONTACT_H_

#include <string>
#include <iostream>
#include <cstdio>

class Contact {
public :
	Contact ();
	Contact (std::string firstname, std::string lastname, std::string nickname, int number, std::string darkestSecret);
	~Contact (void);

	std::string	getFirstname(void);
	std::string	getLastname(void);
	std::string getNickname(void);
	int 		getNumber(void);

	std::string	getDarkestSecret(void);
private :
	std::string	_firstName;
	std::string	_lastName;
	int			_number;
	std::string	_nickname;
	std::string	_darkestSecret;
};

#endif
