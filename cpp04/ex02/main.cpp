/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:31:10 by lemercie          #+#    #+#             */
/*   Updated: 2025/02/19 16:09:48 by lemercie         ###   ########.fr       */
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
/* 	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	Cat *kitty = (Cat*) i;
	std::cout << kitty->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	Dog *doggy = (Dog*) j;
	std::cout << doggy->getType() << " " << std::endl;

	Dog john;
	Dog bob;
	john = bob;
	Dog liz = func(john);

	std::cout << "============ Wrong stuff ===================" << std::endl;
	WrongCat bad_kitty;
	bad_kitty.makeSound();

	delete meta;
	delete i;
	delete j; */

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

	// These lines should fail to compile
	 // Animal impossible;
	 // impossible.getType();
	return 0;
}
