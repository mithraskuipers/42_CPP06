/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScalarConverter.cpp                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/18 19:42:44 by mikuiper      #+#    #+#                 */
/*   Updated: 2023/06/22 15:13:44 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../incs/ScalarConverter.hpp"

/*
** Orthodox canonical form
*/

ScalarConverter::ScalarConverter()
{
	// No logic implemented as the class does not have any member variables.	
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	// No logic implemented as the class does not have any member variables.
	(void)other;
}

ScalarConverter::~ScalarConverter()
{
	// No logic implemented as the class does not have any member variables.
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &other)
{
	// This will always return *this. No matter what happens.
	// What is determined here is what is being put inside this before it is
	// returned.
	if (this != &other)
	{
		// Logic here...
		return (*this);
	}
	return (*this);
}

/*
** Private member functions
*/

// Remember: No need to specify static here
// Remember: Use of references instead of pointers to not have to check of NULL

#include "ScalarConverter.hpp"
#include <cstdlib> // For atoi and atof

void ScalarConverter::convert(const std::string &input)
{
	convertChar(input);
	convertInt(input);
	convertFloat(input);
	convertDouble(input);
}

bool isInteger(const std::string &str)
{
	if (str.empty())
	{
		return false;
	}
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (i == 0 && (str[i] == '-' || str[i] == '+'))
		{
			continue;
		}
		if (!std::isdigit(str[i]))
		{
			return false;
		}
	}
	return true;
}

void ScalarConverter::convertChar(const std::string &input)
{
	std::cout << "char: ";

	// Check if the input is a valid integer
	if (isInteger(input))
	{
		int value = std::atoi(input.c_str()); // Convert input to integer
		char c = static_cast<char>(value);
		if (isDisplayable(c))
			std::cout << "'" << c << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	else
	{
		// Create an input string stream from the given input
		std::istringstream iss(input);

		// Declare a variable to store the floating-point value
		float floatValue;

		// Attempt to extract a float value from the input stream
		if (iss >> floatValue)
		{
			// Convert the float value to an integer
			int intValue = static_cast<int>(floatValue);

			// Convert the integer value to a character
			char c = static_cast<char>(intValue);

			// Check if the character is displayable
			if (isDisplayable(c))
			{
				// Display the character surrounded by single quotes
				std::cout << "'" << c << "'" << std::endl;
			}
			else
			{
				// The character is not displayable
				std::cout << "Non displayable" << std::endl;
			}
		}
		else
		{
			// The input cannot be converted to a float value
			std::cout << "impossible" << std::endl;
		}
	}
}

void ScalarConverter::convertInt(const std::string &input)
{
	std::cout << "int: ";

	// Check if the input is a valid integer
	if (isInteger(input))
	{
		try
		{
			int i = std::atoi(input.c_str()); // Convert input to integer
			std::cout << i << std::endl; // Print the integer value
		}
		catch(const std::exception& error)
		{
			std::cout << "impossible" << std::endl; // Conversion failed, print "impossible"
		}
	}
	else
	{
		try
		{
			float f = std::atof(input.c_str()); // Convert input to float
			int i = static_cast<int>(f); // Truncate float to integer
			if (f == i)
				std::cout << i << std::endl; // If float is an exact integer, print the integer value
			else
				std::cout << "impossible" << std::endl; // Float is not an exact integer, print "impossible"
		}
		catch(const std::exception& error)
		{
			std::cout << "impossible" << std::endl; // Conversion failed, print "impossible"
		}
	}
}

void ScalarConverter::convertFloat(const std::string &input)
{
	std::cout << "float: ";
	try
	{
		// Convert the input string to a float value
		float f = std::atof(input.c_str());

		// With fixed you specify that floats are displayed in fixed-point notation.
		// With setprecision you specifiy that x digits are shown after the decimal point.
		std::cout << std::fixed << std::setprecision(1); 

		// Output the float value with the desired format
		std::cout << f << "f" << std::endl;
	}
	catch (const std::exception& error)
	{
		std::cout << "nanf" << std::endl;
	}
}

// convertDouble is practically identical to convertFloat
void ScalarConverter::convertDouble(const std::string &input)
{
	std::cout << "double: ";
	try
	{
		double d = std::atof(input.c_str());
		std::cout << d << std::endl;
	}
	catch (const std::exception& error)
	{
		std::cout << "nan" << std::endl;
	}
}

bool ScalarConverter::isDisplayable(char c)
{
	return (c >= 32 && c <= 126);
}
