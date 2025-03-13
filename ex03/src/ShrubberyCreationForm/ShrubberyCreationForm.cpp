/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 14:46:02 by shurtado          #+#    #+#             */
/*   Updated: 2025/03/13 16:59:03 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("NoTarget") {}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm("ShrubberyCreationForm", 145, 137), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		this->_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

std::string	ShrubberyCreationForm::print_tree() const
{
	return
	(
		"       /\\\n"
		"      /**\\\n"
		"     /****\\\n"
		"    /******\\\n"
		"   /********\\\n"
		"  /**********\\\n"
		" /************\\\n"
		"/**************\\\n"
		"       ||\n"
		"       ||\n"
		"       ||\n"
	);
}

void	ShrubberyCreationForm::executeAction() const
{
	std::ofstream file((_target + "_shrubbery").c_str());
	if (file.is_open())
	{
		file << print_tree();
		file.close();
		printCute("Trees planted!", Color::green);
	}
	else
		std::cerr << Color::red << "Failed to open File\n" << Color::reset;
}
