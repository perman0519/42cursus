/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:15:12 by junssong          #+#    #+#             */
/*   Updated: 2024/04/08 20:54:44 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <exception>
#include <sstream>
#include <cstdlib>

class BitcoinExchange
{
public:
	BitcoinExchange(std::fstream &file);
	~BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& copy);
	BitcoinExchange& operator=(const BitcoinExchange& obj);

	void	run(std::fstream& file);

	class FileError : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	class NegativeError : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};

	class LargerError : public std::exception
	{
	public:
		virtual const char* what() const throw();
	};
private:
	std::fstream&					_file;
	std::map<std::string, double>	_map;

	void	help_run(std::string& line);
};
