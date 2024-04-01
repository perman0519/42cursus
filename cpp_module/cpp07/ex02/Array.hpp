/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:19:53 by junssong          #+#    #+#             */
/*   Updated: 2024/04/01 12:33:06 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

template <typename T>
class Array
{
	public:
		Array(unsigned int n);
		~Array();
		Array(const Array<T>& copy);
		Array<T>& operator=(const Array<T>& obj);

		T& operator[](unsigned int index);
		unsigned int getSize() const;

	private:
		Array();
		T*				_array;
		unsigned int	_size;
};
