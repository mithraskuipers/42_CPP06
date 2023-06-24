/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Serializer.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/23 20:30:34 by mikuiper      #+#    #+#                 */
/*   Updated: 2023/06/24 09:05:15 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>
#include <stdint.h> // uintptr_t
#include "./../incs/Structs.hpp"

class Serializer
{
	public:
		Serializer();
		~Serializer();
		static uintptr_t serialize(Data* ptr);			// Convert pointer to uintptr_t using reinterpret_cast
		static struct Data* deserialize(uintptr_t raw);	// Convert uintptr_t to pointer using reinterpret_cast
};

#endif