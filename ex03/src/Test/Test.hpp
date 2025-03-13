/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:48:39 by shurtado          #+#    #+#             */
/*   Updated: 2025/03/13 17:51:15 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_HPP
#define TEST_HPP

#include "../ShrubberyCreationForm/ShrubberyCreationForm.hpp"
#include "../RobotomyRequestForm/RobotomyRequestForm.hpp"
#include "../PresidentialPardonForm/PresidentialPardonForm.hpp"
#include "../Intern/Intern.hpp"

void	testIncrementDecrement();
void	testAssignment();
void	testOutOfRange();
void	testShrubberyCreation();
void	testRobotomyRequest();
void	testPresidentialPardon();
void	testExecutionFailure();
void	testExecutionWithoutSignature();
void	testInternCreatesForms();
void	testInternCreatesInvalidForm();

#endif
