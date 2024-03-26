/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 12:03:02 by junssong          #+#    #+#             */
/*   Updated: 2024/03/26 14:51:22 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iostream"
#include "string"
#include "exception"

class Bureaucrat;

class Form
{
public:
	Form(const std::string &name, int signGrade, int executionGrade);
	~Form();
	Form(const Form &form);
	Form &operator=(const Form &form);

	int			getSignGrade() const;
	int			getExecutionGrade() const;
	bool		getSign() const;
	std::string	&getName() const;

	void		beSigned(const Bureaucrat &bureaucrat);

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

private:
	const std::string	name;
	bool				sign;
	const int			signGrade;
	const int			executionGrade;
};

std::ostream &operator<<(std::ostream &out, const Form &form);
