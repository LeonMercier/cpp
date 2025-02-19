/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:20:23 by lemercie          #+#    #+#             */
/*   Updated: 2025/02/19 13:48:21 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() : type("Cat"), brain(new Brain)
{
	std::cout << "Cat constructor called" << std::endl;
}

// why does deleting brain here lead to double free?
Cat::Cat(const Cat &source) : Animal(source), type(source.type)
{
	std::cout << "Cat copy constructor called" << std::endl;
	this->brain = new Brain(*source.brain);
}

Cat	&Cat::operator=(const Cat &source)
{
	std::cout << "Cat copy assignement override called" << std::endl;
	if (this != &source)
	{
		this->~Cat();
		new(this) Cat(source);
		this->brain = new Brain(*source.brain);
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "Cat destructor called" << std::endl;
	delete this->brain;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow meow!" << std::endl;
}

std::string		Cat::getType(void) const
{
	return (type);
}

void	Cat::putThougth(std::string t, int index)
{
	brain->ideas[index] = t;
}

std::string	Cat::getThougth(int index)
{
	return (brain->ideas[index]);
}
