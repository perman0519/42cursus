/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 20:52:07 by junssong          #+#    #+#             */
/*   Updated: 2024/03/26 11:28:38 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

class Intern
{
public:
	Intern();
	~Intern();
	Intern(const Intern &intern);
	Intern &operator=(const Intern &intern);

	AForm	*makeForm(const std::string &name, const std::string &target);

	class FormNotFoundException : public std::exception
	{
	public:
		const char *what() const throw();
	};

private:
	AForm	*robotomy(const std::string& target);
	AForm	*presidential(const std::string& target);
	AForm	*shrubbery(const std::string& target);
};
