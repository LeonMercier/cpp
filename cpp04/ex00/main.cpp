/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 13:31:10 by lemercie          #+#    #+#             */
/*   Updated: 2025/03/03 16:12:18 by lemercie         ###   ########.fr       */
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
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << "j: " << j->getType() << " " << std::endl;
	std::cout << "i: " << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	// Convert Animal pointer back to Cat pointer
	Cat *kitty = (Cat*) i;
	std::cout << kitty->getType() << " " << std::endl;

	// Convert Animal pointer back to Dog pointer
	Dog *doggy = (Dog*) j;
	std::cout << doggy->getType() << " " << std::endl;

	Dog john;
	Dog bob;
	john = bob; // assignement operator
	Dog liz = func(john); // copy constructor
	std::cout << liz.getType() << " " << std::endl;

	std::cout << "============ Wrong stuff ===================" << std::endl;
	WrongAnimal *waa = new WrongCat();
	WrongCat 	*wca = new WrongCat();
	waa->makeSound(); // see above how Animal pointer can still make cat sound
	wca->makeSound();

	delete meta;
	delete i;
	delete j;
	delete waa;
	delete wca;
	return 0;
}
