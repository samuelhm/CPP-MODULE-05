/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:45:00 by shurtado          #+#    #+#             */
/*   Updated: 2025/03/13 17:05:56 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm/ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm/RobotomyRequestForm.hpp"
#include "PresidentialPardonForm/PresidentialPardonForm.hpp"

/* ========================== PRUEBAS ANTERIORES ========================== */

void testSigningSuccess()
{
	try
	{
		Bureaucrat alice("Alice", 5);
		ShrubberyCreationForm contract("Home");

		std::cout << contract << std::endl;
		alice.signForm(contract);
		std::cout << contract << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}

void testSigningFailure()
{
	try
	{
		Bureaucrat bob("Bob", 150); // Bob tiene un grado bajo
		ShrubberyCreationForm taxForm("Garden"); // Se requiere grado 145 para firmar

		std::cout << taxForm << std::endl;
		bob.signForm(taxForm); // Bob NO debe poder firmarlo
		std::cout << taxForm << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}

void testAlreadySignedForm()
{
	try
	{
		Bureaucrat charlie("Charlie", 1);
		RobotomyRequestForm passport("Human");

		std::cout << passport << std::endl;
		charlie.signForm(passport); // Firma el formulario
		charlie.signForm(passport); // Intenta firmarlo de nuevo
		std::cout << passport << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}

void testInvalidFormGrades()
{
	try
	{
		ShrubberyCreationForm invalidHigh("Invalid High"); // No se puede crear con grado > 150 o < 1
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}

/* ========================== NUEVAS PRUEBAS ========================== */

void testShrubberyCreation()
{
	try
	{
		Bureaucrat john("John", 1);
		ShrubberyCreationForm garden("Garden");

		std::cout << garden << std::endl;
		john.signForm(garden);
		john.executeForm(garden); // Debería crear un archivo con árboles en ASCII
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}

void testRobotomyRequest()
{
	try
	{
		Bureaucrat sarah("Sarah", 1);
		RobotomyRequestForm experiment("Subject 42");

		std::cout << experiment << std::endl;
		sarah.signForm(experiment);
		sarah.executeForm(experiment); // Debería haber un 50% de éxito o fallo
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}

void testPresidentialPardon()
{
	try
	{
		Bureaucrat president("President", 1);
		PresidentialPardonForm pardon("Bob");

		std::cout << pardon << std::endl;
		president.signForm(pardon);
		president.executeForm(pardon); // Debería imprimir que Bob ha sido perdonado
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}

void testExecutionFailure()
{
	try
	{
		Bureaucrat intern("Intern", 150);
		ShrubberyCreationForm park("Park");

		std::cout << park << std::endl;
		intern.signForm(park);
		intern.executeForm(park); // ❌ Intern no tiene suficiente rango para ejecutar
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}

void testExecutionWithoutSignature()
{
	try
	{
		Bureaucrat mayor("Mayor", 10);
		RobotomyRequestForm surgery("Patient");

		std::cout << surgery << std::endl;
		mayor.executeForm(surgery); // ❌ No se puede ejecutar porque no está firmado
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}

/* ========================== PRUEBAS EXTRA ========================== */

void testIncrementDecrement()
{
	try
	{
		Bureaucrat b1("Alice", 2);
		std::cout << b1 << std::endl;
		++b1;
		std::cout << "After pre-increment: " << b1 << std::endl;
		b1++;
		std::cout << "After post-increment: " << b1 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
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
		std::cerr << "Exception caught: " << e.what() << std::endl;
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
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
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
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}

	try
	{
		Bureaucrat b2("Frank", 151);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
}

/* ========================== MAIN ========================== */

int main()
{
	Frame::FrameTittle("Testing Increment-Decrement", Color::cyan);
	testIncrementDecrement();
	Frame::FrameTittle("Testing Assignment", Color::cyan);
	testAssignment();
	Frame::FrameTittle("Testing out of Range", Color::cyan);
	testOutOfRange();

	Frame::FrameTittle("Testing Shrubbery Creation", Color::cyan);
	testShrubberyCreation();
	Frame::FrameTittle("Testing Robotomy Request", Color::cyan);
	testRobotomyRequest();
	Frame::FrameTittle("Testing Presidential Pardon", Color::cyan);
	testPresidentialPardon();
	Frame::FrameTittle("Testing Execution Failure", Color::cyan);
	testExecutionFailure();
	Frame::FrameTittle("Testing Execution Without Signature", Color::cyan);
	testExecutionWithoutSignature();

	printCute("\n✅ Todas las pruebas han finalizado ✅\n", Color::bgreen);
	return 0;
}
