/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:13:50 by junssong          #+#    #+#             */
/*   Updated: 2024/04/08 21:21:34 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// void v()
// {
// 	system("leaks btc");
// }

int main(int argc, char **agrv)
{
	// atexit(v);
	if (argc != 2)
		std::cerr << "Error: could not open file." << std::endl;
	std::fstream file(agrv[1], std::ios::in);
	std::fstream file2("data.csv", std::ios::in);
	if (!file.is_open() || !file2.is_open())
	{
		std::cerr << "Error: could not open file." << std::endl;
		return (1);
	}
	BitcoinExchange bitcoinExchange(file2);
	try
	{
		bitcoinExchange.run(file);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (1);
	}
	return (0);
}
