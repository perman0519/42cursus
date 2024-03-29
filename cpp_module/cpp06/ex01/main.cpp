/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 11:01:08 by junssong          #+#    #+#             */
/*   Updated: 2024/03/29 11:07:34 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data data;
	data.data = 42;

	uintptr_t serialized = Serializer::serialize(&data);

	std::cout << "serialized: " << serialized
			<< " data point: " << ((unsigned long)(&data)) << std::endl;

	Data *deserialized = Serializer::deserialize(serialized);
	std::cout << "data.data: " << data.data << std::endl
			<< "deserialized: " << deserialized->data << std::endl;
	return (0);
}
