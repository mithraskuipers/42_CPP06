/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: mikuiper <mikuiper@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/23 20:23:26 by mikuiper      #+#    #+#                 */
/*   Updated: 2023/06/25 00:31:49 by mikuiper      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "./../incs/Base.hpp"
#include "./../incs/A.hpp"
#include "./../incs/B.hpp"
#include "./../incs/C.hpp"

#include <cstdlib> // for rand
#include <ctime>

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
	try
	{
		A& a = dynamic_cast<A&>(p);
		std::cout << "Identified pointer as type: A" << std::endl;
		(void)a; // Silence unused variable warning
		return;
	}
	catch (const std::bad_cast& e) {}

	try
	{
		B& b = dynamic_cast<B&>(p);
		std::cout << "Identified pointer as type: B" << std::endl;
		(void)b; // Silence unused variable warning
		return;
	}
	catch (const std::bad_cast& e) {}

	try
	{
		C& c = dynamic_cast<C&>(p);
		std::cout << "Identified pointer as type: C" << std::endl;
		(void)c; // Silence unused variable warning
		return;
	}
	catch (const std::bad_cast& e) {}

	std::cout << "Unable to identify pointer type." << std::endl;
}

int main()
{
	Base *test = generate();
	identify(test);
	delete (test);
	return (0);
}
