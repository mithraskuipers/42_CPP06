/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/23 20:23:26 by mikuiper      #+#    #+#                 */
/*   Updated: 2023/06/25 00:11:26 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../incs/Base.hpp"
#include "./../incs/A.hpp"
#include "./../incs/B.hpp"
#include "./../incs/C.hpp"

#include <cstdlib> // for rand
#include <ctime>
#include <typeinfo>

Base *generate(void)
{
	//std::srand(42); // set seed
	std::time_t currentTime = std::time(NULL);
	unsigned int currentTimeUINT = static_cast<unsigned int>(currentTime);
	std::srand(currentTimeUINT); // set the seed
	int randomNumber = std::rand();
	int caseNumber = randomNumber % 3;
	switch (caseNumber)
	{
		case 0:
		{
			// std::cout << "0" << std::endl;
			return (new A());
		}
		case 1:
		{
			// std::cout << "1" << std::endl;
			return (new B());
		}
		default: // simulate "else" statement
		{
			// std::cout << "2" << std::endl;
			return (new C());
		}
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
	{
		std::cout << "Identified pointer as type: A" << std::endl;
	}
	else if (dynamic_cast<B*>(p))
	{
		std::cout << "Identified pointer as type: B" << std::endl;	
	}
	else if (dynamic_cast<C*>(p))
	{
		std::cout << "Identified pointer as type: C" << std::endl;
	}
	else
	{
		std::cout << "Unable to identify object type." << std::endl;
	}
}

void identify(Base& p)
{
	if (typeid(p) == typeid(A)) // Look at typeid of class A
	{
		std::cout << "Identified ref: A" << std::endl;
		return ;
	}
	else if (typeid(p) == typeid(B)) // Look at typeid of class B
	{
		std::cout << "Identified ref: B" << std::endl;
		return ;
	}
	else if (typeid(p) == typeid(C)) // Look at typeid of class C
	{
		std::cout << "Identified ref: C" << std::endl;
		return ;
	}
	else
	{
		std::cout << "Unknown type" << std::endl;
		return ;
	}
}

int main()
{
	Base *test = generate();
	identify(test);
	delete (test);
	return (0);
}