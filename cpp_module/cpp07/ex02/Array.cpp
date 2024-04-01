/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:26:38 by junssong          #+#    #+#             */
/*   Updated: 2024/04/01 12:33:13 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

template <typename T>
Array<T>::Array(unsigned int n) :
	_size(n)
{
	std::cout << "Array constructor called" << std::endl;
	_array = new T[n];
}

template <typename T>
Array<T>::~Array()
{
	std::cout << "Array destructor called" << std::endl;
	delete[] _array;
}

template <typename T>
Array<T>::Array(const Array<T>& copy) :
	_size(copy._size)
{
	std::cout << "Array copy constructor called" << std::endl;
	*this = copy;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& obj)
{
	std::cout << "Array assignation operator called" << std::endl;
	if (this == &obj)
		return (*this);
	delete[] _array;
	_array = new T[_size];
	for (unsigned int i = 0; i < _size; i++)
		_array[i] = obj._array[i];
	return (*this);
}

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw std::exception();
	return (_array[index]);
}

template <typename T>
unsigned int Array<T>::getSize() const
{
	return (_size);
}
