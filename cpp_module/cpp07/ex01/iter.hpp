/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 19:40:48 by junssong          #+#    #+#             */
/*   Updated: 2024/04/01 13:11:08 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>
void iter(const T *array, size_t size, void (*func)(const T &))
{
	for (size_t i = 0; i < size; i++)
		func(array[i]);
}

template <typename T>
void iter(T *array, size_t size, void (*func)(T &))
{
	for (size_t i = 0; i < size; i++)
		func(array[i]);
}
