/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 10:29:31 by junssong          #+#    #+#             */
/*   Updated: 2024/03/29 13:09:38 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Data.hpp"

typedef unsigned long uintptr_t;

class Serializer
{
	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);

	private:
		Serializer();
		Serializer(const Serializer &serializer);
		~Serializer();
		Serializer &operator=(const Serializer &serializer);
};
