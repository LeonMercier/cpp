/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:31:10 by lemercie          #+#    #+#             */
/*   Updated: 2025/02/17 18:07:09 by lemercie         ###   ########.fr       */
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
		zoo[i]->putThougth("Bark", 2);
	}
	for (int i = 5; i < 10; i++)
	{
		zoo[i] = new Cat;
		zoo[i]->putThougth("Meow", 3);
	}
	zoo[4]->makeSound();
	std::cout << zoo[4]->getThougth(2) << std::endl;
	zoo[5]->makeSound();
	std::cout << zoo[5]->getThougth(3) << std::endl;

	Cat kitty;
	Cat demon;
	kitty.putThougth("Skree", 4);
	demon = kitty;
	std::cout << demon.getThougth(4) << std::endl;
	std::cout << kitty.getThougth(4) << std::endl;

	for (int i = 0; i < 10; i++)
	{
		delete zoo[i];
	}
	return 0;
}
