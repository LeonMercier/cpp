/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:31:10 by lemercie          #+#    #+#             */
/*   Updated: 2025/03/03 15:20:32 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Animal.hpp"
#include "WrongCat.hpp"

Dog	func(Dog dog)
{
	dog.makeSound();
	return (dog);
}

int main()
{
	Animal	*zoo[10];
	for (int i = 0; i < 5; i++)
	{
		zoo[i] = new Dog;
	}
	for (int i = 5; i < 10; i++)
	{
		zoo[i] = new Cat;
	}
	zoo[4]->makeSound();
	zoo[5]->makeSound();
	for (int i = 0; i < 10; i++)
	{
		delete zoo[i];
	}


	Cat kiki;
	Cat demon;
	for (int i = 0; i < 100; i++)
	{
		kiki.putIdea(i, "Skree");
	}
	for (int i = 0; i < 100; i++)
	{
		demon.putIdea(i, "demonic idea");
	}
	demon = kiki; //deep copy
	std::cout << demon.getIdea(99) << std::endl;
	std::cout << kiki.getIdea(99) << std::endl;
	std::cout << kiki.getType() << std::endl;
	std::cout << demon.getType() << std::endl;
 
	Cat	asd;
	asd.putIdea(5, "asd idea");
	{
		Cat fgh;
		fgh.putIdea(5, "fgh idea");
		asd = fgh;
	} // fgh falls out of scope and is destroyed here
	std::cout << "Deep copy? " << asd.getIdea(5) << std::endl;
//	std::cout << "Deep copy? " << fgh.getIdea(5) << std::endl;

	return 0;
}
