/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 11:08:11 by junssong          #+#    #+#             */
/*   Updated: 2024/01/08 17:56:28 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char **argv) {
	std::string tmp;
	argv++;
	if (argc == 1)
	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int j = 1; j < argc; j++)
	{
		tmp = *argv;
		for (size_t i = 0; i < tmp.length(); i++)
			std::cout << static_cast<char>(toupper(tmp[i])); //cpp style
		argv++;
	}
	std::cout << std::endl;
	return 0;
}
