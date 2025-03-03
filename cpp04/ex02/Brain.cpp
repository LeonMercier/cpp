/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:20:23 by lemercie          #+#    #+#             */
/*   Updated: 2025/03/03 14:51:47 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"


Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &source)
{
	std::cout << "Brain copy constructor called" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		ideas[i] = source.ideas[i];
	}
}

Brain	&Brain::operator=(const Brain &source)
{
	std::cout << "Brain copy assignement override called" << std::endl;
	if (this != &source)
	{
		for (int i = 0; i < 100; i++)
		{
			ideas[i] = source.ideas[i];
		}
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}
	
void		Brain::putIdea(int index, std::string idea)
{
	ideas[index] = idea;
}

std::string	Brain::getIdea(int index) const
{
	return (ideas[index]);
}

