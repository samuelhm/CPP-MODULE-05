/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 11:54:47 by shurtado          #+#    #+#             */
/*   Updated: 2025/03/11 19:21:02 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat/Bureaucrat.hpp"

void testIncrementDecrement()
{
	try
	{
		Bureaucrat b1("Alice", 2);
		std::cout << b1 << std::endl;
		++b1;
		std::cout << "After pre-increment: ";
		std::cout << b1 << std::endl;
		b1++;
		std::cout << "After post-increment: " << b1 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << Color::red << e.what() << Color::reset << std::endl;
	}
	try
	{
		Bureaucrat b2("Bob", 149);
		std::cout << b2 << std::endl;
		--b2;
		std::cout << "After pre-decrement: " << b2 << std::endl;
		b2--;
		std::cout << "After post-decrement: " << b2 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << Color::red << e.what() << Color::reset << std::endl;
	}
}

void testAssignment()
{
	try
	{
		Bureaucrat b1("Charlie", 10);
		Bureaucrat b2("Dave", 20);
		b2 = b1;
		std::cout << b2 << std::endl;
	}
	catch (const std::exception &e) {
	std::cerr << "Exception caught: " << Color::red << e.what() << Color::reset << std::endl;
	}
}

void testOutOfRange()
{
	try
	{
		Bureaucrat b1("Eve", 0);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << Color::red << e.what() << Color::reset << std::endl;
	}

	try
	{
		Bureaucrat b2("Frank", 151);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << Color::red << e.what() << Color::reset << std::endl;
	}
}

int main()
{
	Frame::FrameTittle("Testing Increment-Decrement", Color::cyan);
	testIncrementDecrement();
	Frame::FrameTittle("Testing Assignment", Color::cyan);
	testAssignment();
	Frame::FrameTittle("Testing out of Range", Color::cyan);
	testOutOfRange();
	return 0;
}
