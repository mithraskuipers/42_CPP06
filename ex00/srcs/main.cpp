/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/23 20:23:30 by mikuiper      #+#    #+#                 */
/*   Updated: 2023/06/23 20:23:30 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../incs/ScalarConverter.hpp"

int main(int argc, char **argv)
{
		ScalarConverter test1;

		if (argc != 2)
		{
				std::cout << "Error: Wrong number of arguments" << std::endl;
				return 1;
		}
		test1.convert(argv[1]);
	return 0;
}
