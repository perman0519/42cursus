/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 20:17:35 by junssong          #+#    #+#             */
/*   Updated: 2024/03/14 13:28:13 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "iostream"
#include "string"
#include "exception"

class Bureaucrat;

class AForm
{
public:
	AForm(const std::string &name, int signGrade, int executionGrade);
	virtual ~AForm();
	AForm(const AForm &form);
	AForm &operator=(const AForm &form);

	int				getSignGrade() const;
	int				getExecutionGrade() const;
	bool			getSign() const;
	std::string		&getName() const;

	void			beSigned(const Bureaucrat &bureaucrat);
	virtual void	execute(Bureaucrat const & executor) const = 0;

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
	AForm();
	const std::string	name;
	bool				sign;
	const int			signGrade;
	const int			executionGrade;

};

std::ostream &operator<<(std::ostream &out, const AForm &form);
