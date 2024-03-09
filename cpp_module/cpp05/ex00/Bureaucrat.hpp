/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:31:01 by junssong          #+#    #+#             */
/*   Updated: 2024/03/09 11:59:07 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <iostream>
#include <string>

const std::string red("\033[0;31m");
const std::string green("\033[1;32m");
const std::string reset("\033[0m");

class Bureaucrat
{
public :
	Bureaucrat(const std::string &name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &bureaucrat);
	Bureaucrat &operator=(const Bureaucrat &bureaucrat);

	std::string	&getName() const;
	int			getGrade() const;

private :
	Bureaucrat();
	const std::string	name;
	int					grade;

	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw();
	};

};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);
