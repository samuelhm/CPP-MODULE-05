/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 20:00:55 by shurtado          #+#    #+#             */
/*   Updated: 2025/03/11 21:15:13 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Form.hpp"

Form::Form() : _name("unnamed"), _signed(false), _signGrade(1), _execGrade(1) {}

Form::Form(const std::string name,const int signGrade, const int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (execGrade > 150 || signGrade > 150)
		throw GradeTooLowException();
	else if (execGrade < 1 || signGrade < 1)
		throw GradeTooHighException();
}

Form::Form(const Form &other) : _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _execGrade(other._execGrade) {}

Form& Form::operator=(const Form &other)
{
	(void)other;
	throw std::runtime_error("You cannot assign a Form to another!");
}

Form::~Form() {}

std::string Form::getName() const { return _name; }
bool		Form::getSigned() const { return _signed; }
int			Form::getSignGrade() const { return _signGrade; }
int			Form::getExecGrade() const { return _execGrade; }

void		Form::beSigned(const Bureaucrat &b)
{
	if (_signed)
	{
		throw std::runtime_error("Already Signed!!!");
	}
	else if (b.getGrade() > _signGrade)
		throw GradeTooLowException();
	if (!_signed)
		_signed = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Form grade is too High!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Form grade is too Low!";
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << Color::underline << form.getName() << Color::reset << " signed: ";
	if (form.getSigned())
		os << Color::green << "yes." << Color::reset;
	else
		os << Color::red << "no." << Color::reset;
	os << " sign grade: " << Color::bblue << form.getSignGrade() << Color::reset;
	os << " execution grade: " << Color::bblue << form.getExecGrade() << Color::reset;
	return (os);
}
