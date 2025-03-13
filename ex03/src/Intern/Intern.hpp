/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:21:48 by shurtado          #+#    #+#             */
/*   Updated: 2025/03/13 17:40:34 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef INTERN_HPP
#define INTERN_HPP

#include "../AForm/AForm.hpp"
#include "../PresidentialPardonForm/PresidentialPardonForm.hpp"
#include "../RobotomyRequestForm/RobotomyRequestForm.hpp"
#include "../ShrubberyCreationForm/ShrubberyCreationForm.hpp"

class Intern
{
	private:
		static AForm* createRobotomyRequest(const std::string &target);
		static AForm* createShrubberyCreation(const std::string &target);
		static AForm* createPresidentialPardon(const std::string &target);
	public:
		Intern();
		Intern(const Intern &other);
		Intern& operator=(const Intern &other);
		~Intern();

		AForm *makeForm(const std::string &formname, const std::string &target) const;
};

#endif
