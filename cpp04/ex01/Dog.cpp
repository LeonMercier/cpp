/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:20:23 by lemercie          #+#    #+#             */
/*   Updated: 2025/03/03 14:56:13 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() : brain(new Brain)
{
	std::cout << "Dog constructor called" << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog &source) : Animal(source)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->brain = new Brain(*source.brain);
}

Dog	&Dog::operator=(const Dog &source)
{
	std::cout << "Dog copy assignement override called" << std::endl;
	if (this != &source)
	{
		delete this->brain;
		Animal::operator=(source);
		this->brain = new Brain(*source.brain);
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->brain;
}

void	Dog::makeSound(void) const
{
	std::cout << "Bark bark!" << std::endl;
}

std::string	Dog::getType(void) const
{
	return (type);
}

void	Dog::putIdea(int index, std::string idea)
{
	brain->putIdea(index, idea);
}

std::string	Dog::getIdea(int index) const
{
	return (brain->getIdea(index));
}
