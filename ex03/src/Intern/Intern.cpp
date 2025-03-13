/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:21:55 by shurtado          #+#    #+#             */
/*   Updated: 2025/03/13 17:42:55 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &other) { *this = other; }

Intern& Intern::operator=(const Intern &other) { (void)other; return *this; }

Intern::~Intern() {}

AForm* Intern::makeForm(const std::string &name, const std::string &target) const
{
	struct FormEntry
	{
		const char* name;
		AForm* (*create)(const std::string&);
	};

	static FormEntry forms[] =
	{
		{ "robotomy request", &Intern::createRobotomyRequest },
		{ "shrubbery creation", &Intern::createShrubberyCreation },
		{ "presidential pardon", &Intern::createPresidentialPardon }
	};

	for (int i = 0; i < 3; i++)
	{
		if (name == forms[i].name)
		{
			std::cout << "Intern creates " << name << std::endl;
			return forms[i].create(target);
		}
	}
	std::cerr << Color::red << "Error: Form '" << name << "' not found!" << Color::reset << std::endl;
	return NULL;
}

AForm* Intern::createRobotomyRequest(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::createShrubberyCreation(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

AForm* Intern::createPresidentialPardon(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}
