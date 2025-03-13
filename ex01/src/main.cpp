/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 11:54:47 by shurtado          #+#    #+#             */
/*   Updated: 2025/03/11 21:20:15 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat/Bureaucrat.hpp"

void testSigningSuccess()
{
	try
	{
		Bureaucrat alice("Alice", 5);
		Form contract("Contract", 10, 20);

		std::cout << contract << std::endl;
		alice.signForm(contract);
		std::cout << contract << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "exception caught: " << e.what() << std::endl;
	}
}

void testSigningFailure()
{
	try
	{
		Bureaucrat bob("Bob", 50); // Bob tiene un grado bajo
		Form taxForm("Tax Form", 20, 30); // Se requiere grado 20 para firmar

		std::cout << taxForm << std::endl;
		bob.signForm(taxForm); // Bob NO debe poder firmarlo
		std::cout << taxForm << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "exception caught: " << e.what() << std::endl;
	}
}

void testAlreadySignedForm()
{
	try
	{
		Bureaucrat charlie("Charlie", 5);
		Form passport("Passport", 10, 15);

		std::cout << passport << std::endl;
		charlie.signForm(passport); // Firma el formulario
		charlie.signForm(passport); // Intenta firmarlo de nuevo
		std::cout << passport << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "exception caught: " << e.what() << std::endl;
	}
}

void testInvalidFormGrades()
{
	try
	{
		Form invalidHigh("Invalid High", 0, 10); // Grado de firma demasiado alto
	}
	catch (const std::exception &e)
	{
		std::cerr << "exception caught: " << e.what() << std::endl;
	}

	try
	{
		Form invalidLow("Invalid Low", 151, 140); // Grado de firma demasiado bajo
	}
	catch (const std::exception &e)
	{
		std::cerr << "exception caught: " << e.what() << std::endl;
	}
}

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

	Frame::FrameTittle("Sign Success.", Color::cyan);
	testSigningSuccess();
	Frame::FrameTittle("Sign Failure.", Color::cyan);
	testSigningFailure();
	Frame::FrameTittle("Already Signed.", Color::cyan);
	testAlreadySignedForm();
	Frame::FrameTittle("Invalid Grades.", Color::cyan);
	testInvalidFormGrades();

	printCute("\n✅ Todas las pruebas han finalizado ✅\n", Color::bgreen);
	return 0;
}
