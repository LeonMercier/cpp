/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:20:23 by lemercie          #+#    #+#             */
/*   Updated: 2025/01/31 15:47:55 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"


Animal::Animal() : type("Default animal")
{
	std::cout << "Animal constructor called" << std::endl;
	brain = new Brain;
}

Animal::Animal(const Animal &source) : type(source.type), brain(source.brain)
{
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal	&Animal::operator=(const Animal &source)
{
	std::cout << "Animal copy assignement override called" << std::endl;
	if (this != &source)
	{
		type = source.type;
		brain = source.brain;
	}
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
	delete brain;
}

void	Animal::makeSound(void) const
{
	std::cout << "Default animal sound" << std::endl;
}

std::string		Animal::getType(void) const
{
	return (type);
}

