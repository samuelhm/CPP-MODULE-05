/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:45:00 by shurtado          #+#    #+#             */
/*   Updated: 2025/03/13 17:50:56 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Test/Test.hpp"

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

	Frame::FrameTittle("Testing Intern create Form", Color::cyan);
	testInternCreatesForms();
	Frame::FrameTittle("Testing Intern Failure Forms", Color::cyan);
	testInternCreatesInvalidForm();
	printCute("\n✅ Todas las pruebas han finalizado ✅\n", Color::bgreen);
	return 0;
}
