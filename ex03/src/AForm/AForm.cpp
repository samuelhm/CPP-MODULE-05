/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 20:00:55 by shurtado          #+#    #+#             */
/*   Updated: 2025/03/13 16:58:02 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AForm.hpp"

AForm::AForm() : _name("unnamed"), _signed(false), _signGrade(1), _execGrade(1) {}

AForm::AForm(const std::string name,const int signGrade, const int execGrade) : _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (execGrade > 150 || signGrade > 150)
		throw GradeTooLowException();
	else if (execGrade < 1 || signGrade < 1)
		throw GradeTooHighException();
}

AForm::AForm(const AForm &other) : _name(other._name), _signed(other._signed), _signGrade(other._signGrade), _execGrade(other._execGrade) {}

AForm::~AForm() {}

std::string AForm::getName() const { return _name; }
bool		AForm::getSigned() const { return _signed; }
int			AForm::getSignGrade() const { return _signGrade; }
int			AForm::getExecGrade() const { return _execGrade; }

void		AForm::beSigned(const Bureaucrat &b)
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

void		AForm::execute(const Bureaucrat &executor) const
{
	if (!_signed)
		throw NotSignedException();
	if (executor.getGrade() > _execGrade)
		throw GradeTooLowException();
	executeAction();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Form: grade is too High!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Form: grade is too Low!";
}

const char* AForm::NotSignedException::what() const throw()
{
	return "Form is not signed!";
}

std::ostream &operator<<(std::ostream &os, const AForm &AForm)
{
	os << Color::underline << AForm.getName() << Color::reset << " signed: ";
	if (AForm.getSigned())
		os << Color::green << "yes." << Color::reset;
	else
		os << Color::red << "no." << Color::reset;
	os << " sign grade: " << Color::bblue << AForm.getSignGrade() << Color::reset;
	os << " execution grade: " << Color::bblue << AForm.getExecGrade() << Color::reset;
	return (os);
}
