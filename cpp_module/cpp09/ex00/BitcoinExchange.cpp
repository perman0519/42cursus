/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 15:15:03 by junssong          #+#    #+#             */
/*   Updated: 2024/04/09 14:55:40 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::fstream &file) :
	_file(file)
{
	std::string	line;
	std::string	key;
	char *		err = NULL;
	double		value;
	std::getline(_file, line);
	while (std::getline(_file, line))
	{
		key = line.substr(0, line.find(','));
		value = std::strtod(line.substr(line.find(',') + 1).c_str(), &err);
		if (*err)
			throw FileError();
		_map[key] = value;
		err = NULL;
	}
	_file.close();
	// std::cout << "bitcoinExchange constructor called." << std::endl;
}

BitcoinExchange::~BitcoinExchange()
{
	// std::cout << "bitcoinExchange distructor called." << std::endl;
}

const char*	BitcoinExchange::FileError::what() const throw()
{
	return ("Error: bad input");
}

const char*	BitcoinExchange::NegativeError::what() const throw()
{
	return ("Error: not a postive number.");
}

const char*	BitcoinExchange::LargerError::what() const throw()
{
	return ("Error: too large a number.");
}

void BitcoinExchange::run(std::fstream& file)
{
	std::string	line;

	std::getline(file, line);
	if (line != "date | value")
		throw FileError();
	while (std::getline(file, line))
	{
		try
		{
			help_run(line);
		}
		catch(const BitcoinExchange::FileError& e)
		{
			std::cerr << e.what() << " => " << line << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}

void	BitcoinExchange::help_run(std::string& line)
{
	std::string	date;
	std::string	ss_str;
	std::string	str_value;
	double		value;
	double		db_value = 0.0;
	char*		err = NULL;
	int			month, year, day;

	date = line.substr(0, line.find(" | "));
	std::stringstream stringStream(date);
	int count = 0;
	while (std::getline(stringStream, ss_str, '-'))
	{
		count++;
		switch (count)
		{
		case 1:
			year = (int)std::strtod(ss_str.c_str(), &err);
			if ((year <= 0 || year >= 9999) || *err)
				throw FileError();
			err = NULL;
			break;

		case 2:
			month =  (int)std::strtod(ss_str.c_str(), &err);
			if ((month <= 0 || month >= 13) || *err)
				throw FileError();
			err = NULL;
			break;

		case 3:
			day =  (int)std::strtod(ss_str.c_str(), &err);
			if (day <= 0 || *err)
				throw FileError();
			if (month == 2 && day >= 29)
				throw FileError();
			else if ((month == 4 || month == 6 || month == 9 || month == 11) && day >= 31)
				throw FileError();
			else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
			{
				if (day >= 32)
					throw FileError();
			}
			break;

		default:
			break;
		}
	}
	if (count < 3)
		throw FileError();
	str_value = line.substr(line.find(" | ") + 3);
	err = NULL;
	value = std::strtod(str_value.c_str(), &err);
	if (*err)
		throw FileError();
	if (value < 0)
		throw NegativeError();
	if (value > 1000)
		throw LargerError();
	for (std::map<std::string, double>::iterator it = _map.begin(); it != _map.end(); it++)
	{
		if (date < it->first)
		{
			if (it != _map.begin())
				db_value = (--it)->second;
			else
				db_value = it->second;
			break ;
		}
		if (it == --_map.end())
			db_value = it->second;
	}
	std::cout << date << " => " << value << " = " << value * db_value << std::endl;
}
