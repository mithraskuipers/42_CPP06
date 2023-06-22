/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/22 15:49:34 by mikuiper      #+#    #+#                 */
/*   Updated: 2023/06/22 15:56:27 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../incs/ScalarConverter.hpp"

/*
** Orthodox canonical form
*/

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter default constructor called" << std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter destructor called" << std::endl;
}

/*
** Orthodox canonical form
*/

void ScalarConverter::convert(std::string input)
{
	// Convert to char
	std::cout << "char: ";
	try
	{
		int intValue = atoi(input.c_str());
		char c = static_cast<char>(intValue);
		if (c < 32 || c > 126)
		{
			std::cout << "Non displayable" << std::endl;
		}
		else
		{
			std::cout << "'" << c << "'" << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cout << "impossible" << std::endl;
	}
	// Convert to int
	std::cout << "int: ";
	try
	{
		int i = atoi(input.c_str());
		std::cout << i << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "impossible" << std::endl;
	}
	// Convert to float
	std::cout << "float: ";
	try
	{
		float f = static_cast<float>(atof(input.c_str()));
		std::printf("%.1ff\n", f);
	}
	catch(const std::exception& e)
	{
		std::cout << "impossible" << std::endl;
	}
	// Convert to double
	std::cout << "double: ";
	try
	{
		double d = atof(input.c_str());
		std::printf("%.1f\n", d);
	}
	catch(const std::exception& e)
	{
		std::cout << "impossible" << std::endl;
	}
}
