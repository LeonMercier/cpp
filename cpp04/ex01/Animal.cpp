/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:20:23 by lemercie          #+#    #+#             */
/*   Updated: 2025/02/18 17:27:19 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"


Animal::Animal() : type("Default animal")
{
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &source) : type(source.type) 
{
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal	&Animal::operator=(const Animal &source)
{
	std::cout << "Animal copy assignement override called" << std::endl;
	if (this != &source)
	{
		this->type = source.type;
		// this->~Animal();
		// new(this) Animal(source);
		// delete this->brain;
		// this->brain = new Brain(*source.brain);
	}
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

void	Animal::makeSound(void) const
{
	std::cout << "Default animal sound" << std::endl;
}

std::string		Animal::getType(void) const
{
	return (type);
}

