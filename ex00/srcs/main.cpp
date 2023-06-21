/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/20 23:24:58 by mikuiper      #+#    #+#                 */
/*   Updated: 2023/06/21 23:20:33 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../incs/ScalarConverter.hpp"
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "Usage: ./convert <literal>" << std::endl;
        return 1;
    }

    std::string literal = argv[1];
    ScalarConverter::convert(literal);
    return 0;
}
