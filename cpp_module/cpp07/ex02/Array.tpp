/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 12:26:38 by junssong          #+#    #+#             */
/*   Updated: 2024/04/03 10:20:29 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Array.hpp"

template <typename T>
Array<T>::Array() :
	_size(0)
{
	std::cout << "Array constructor called" << std::endl;
	_array = new T[0];
}

template <typename T>
Array<T>::Array(unsigned int n) :
	_size(n)
{
	std::cout << "Array constructor called" << std::endl;
	_array = new T[_size];
}


template <typename T>
Array<T>::~Array()
{
	std::cout << "Array destructor called" << std::endl;
	delete[] _array;
}

template <typename T>
Array<T>::Array(const Array<T>& copy) :
	_size(copy._size),
	_array(new T[copy._size])
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
	if (index < 0 || index >= _size)
		throw Array::OutofIndex();
	return (_array[index]);
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
	if (index < 0 || index >= _size)
		throw Array::OutofIndex();
	return (_array[index]);
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (_size);
}

template <typename T>
const char *Array<T>::OutofIndex::what() const throw()
{
	return ("Out of index");
}
