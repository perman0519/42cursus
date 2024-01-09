/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 14:09:42 by junssong          #+#    #+#             */
/*   Updated: 2024/01/08 15:51:37 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PHONEBOOK_H_
#define _PHONEBOOK_H_

#include <iomanip>
#include "./Contact.hpp"
class PhoneBook {

public :
	PhoneBook ();
	~PhoneBook ();
	void	add();
	void	search();

private :
	Contact	contactArr[8];
	int		contactCount;
	int		contactIndex;

	void	coutSearch(std::string str);
	void	coutSearch(int num);
	int		checkEmpty(std::string str);
};

#endif
