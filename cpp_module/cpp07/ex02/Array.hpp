/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:19:53 by junssong          #+#    #+#             */
/*   Updated: 2024/04/03 10:17:07 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <exception>

template <typename T>
class Array
{
	public:
		Array(unsigned int n);
		Array();
		~Array();
		Array(const Array<T>& copy);
		Array<T>& operator=(const Array<T>& obj);

		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;
		unsigned int size() const;

		class OutofIndex : public std::exception
		{
		public:
			const char *what() const throw();
		};

	private:
		unsigned int	_size;
		T*				_array;
};
