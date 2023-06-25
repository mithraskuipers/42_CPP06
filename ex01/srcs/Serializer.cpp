/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Serializer.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/23 20:29:46 by mikuiper      #+#    #+#                 */
/*   Updated: 2023/06/24 09:03:43 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../incs/Serializer.hpp"

/*
** Orthodox canonical form
*/

Serializer::Serializer()
{
	std::cout << "Serializer default constructor called" << std::endl;
}

Serializer::~Serializer()
{
	std::cout << "Serializer destructor called" << std::endl;

}

/*
** Member functions
*/

// Serialization: Converting a pointer to a numerical value
uintptr_t Serializer::serialize(Data* ptr)
{
	// Reinterpret the pointer as uintptr_t
	return reinterpret_cast<uintptr_t>(ptr);
}

// Deserialization: Convert a numerical value (back) to a pointer
Data* Serializer::deserialize(uintptr_t raw)
{
	// Reinterpret the uintptr_t value as a pointer to Data
	return reinterpret_cast<Data*>(raw);
}
