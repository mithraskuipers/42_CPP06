/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/23 20:23:26 by mikuiper      #+#    #+#                 */
/*   Updated: 2023/06/24 09:31:23 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../incs/Serializer.hpp"

int main()
{
	Serializer serializer_object;
	Data data_object1;
	data_object1.s1 = "Mithras";
	data_object1.s2 = "Kuipers";
	data_object1.n = 42;
	uintptr_t serialized_data_object = serializer_object.serialize(&data_object1);
	// Prints the serialized representation of the Data object.
	// This is a value that represents the memory address of the Data object.
	std::cout << "serialized_data_object: " << serialized_data_object << std::endl;
	Data* deserialized_data_object = serializer_object.deserialize(serialized_data_object);
	std::cout << "deserialized_data_object s1: " << deserialized_data_object->s1 << std::endl;
	std::cout << "deserialized_data_object s2: " << deserialized_data_object->s2 << std::endl;
	std::cout << "deserialized_data_object n: " << deserialized_data_object->n << std::endl;
	bool isIdentical = (data_object1.s1 == deserialized_data_object->s1) &&
					   (data_object1.s2 == deserialized_data_object->s2) &&
					   (data_object1.n == deserialized_data_object->n);
	
	if (isIdentical)
	{
		std::cout << "data_object1 is identical to deserialized_data_object: YES" << std::endl;
	}
	else
	{
		std::cout << "data_object1 is identical to deserialized_data_object: NO" << std::endl;
	}
	
	return 0;
}
