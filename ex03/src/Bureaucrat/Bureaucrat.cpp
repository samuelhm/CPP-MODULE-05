/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 11:54:03 by shurtado          #+#    #+#             */
/*   Updated: 2025/03/13 17:11:44 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Unnamed"), _grade(150) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name)
{
	if (other._grade < 1)
		throw GradeTooHighException();
	else if (other._grade > 150)
		throw GradeTooLowException();
	_grade = other._grade;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other)
{
	(void)other;
	throw std::runtime_error("You cannot assign a Bureaucrat to another!");
}

Bureaucrat::~Bureaucrat() {}

std::string Bureaucrat::getName() const { return _name; }
int			Bureaucrat::getGrade() const { return _grade; }

Bureaucrat& Bureaucrat::operator++()
{
	if (_grade <= 1)
		throw GradeTooHighException();
	--_grade;
	return *this;
}

Bureaucrat& Bureaucrat::operator--()
{
	if (_grade >= 150)
		throw GradeTooLowException();
	++_grade;
	return *this;
}

Bureaucrat Bureaucrat::operator++(int)
{
	Bureaucrat temp = *this;
	++(*this);
	return temp;
}

Bureaucrat Bureaucrat::operator--(int)
{
	Bureaucrat temp = *this;
	--(*this);
	return temp;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

void	Bureaucrat::signForm(AForm &form) const
{
	try
	{
		form.beSigned(*this);
		printCute(_name, Color::green);
		printCute(" signed ", Color::reset);
		printCute(form.getName() + "\n", Color::underline);
	}
	catch (const std::exception &e)
	{
		std::cerr << Color::red << _name << " couldn’t sign " << form.getName() << " because " << e.what() << Color::reset << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm &form) const
{
	try
	{
		form.execute(*this);
		printCute(_name, Color::blue);
		printCute(" executed ", Color::reset);
		printCute(form.getName(), Color::underline);
		std::cout << std::endl;
	}
	catch (const std::exception &e)
	{
		printCute(_name, Color::blue);
		printCute(" couldn't execute ", Color::reset);
		printCute(form.getName(), Color::underline);
		printCute(" becouse ", Color::reset);
		printCute(e.what(), Color::red);
		std::cout << std::endl;
	}
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << Color::green << bureaucrat.getName() << Color::reset;
	os << ", bureaucrat grade " << Color::bblue << bureaucrat.getGrade() << Color::reset;
	return (os);
}
