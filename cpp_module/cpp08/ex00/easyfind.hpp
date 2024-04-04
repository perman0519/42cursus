/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 17:02:16 by junssong          #+#    #+#             */
/*   Updated: 2024/04/04 12:01:17 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &container, int n)
{
	return (std::find(container.begin(), container.end(), n));
}

template <typename T>
typename T::const_iterator easyfind(const T &container, int n)
{
	return (std::find(container.cbegin(), container.cend(), n));
}
