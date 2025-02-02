/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:31:30 by lemercie          #+#    #+#             */
/*   Updated: 2025/02/02 16:49:23 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
	Cure *c = new Cure();
	Cure *d = (Cure *) c->clone();
	std::cout << d->getType() << std::endl;

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	AMateria* tmp2;

	tmp = src->createMateria("ice");
	if (tmp == nullptr)
	{std::cout << "no materia created" << std::endl;}
	std::cout << "TYPE: " << tmp->getType() << std::endl;
	me->equip(tmp);

	tmp2 = src->createMateria("cure");
	if (tmp2 == nullptr)
	{
		std::cout << "no materia created" << std::endl;
		return (1);
	}
	std::cout << "TYPE: " << tmp2->getType() << std::endl;
	me->equip(tmp2);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;


	return (0);
}
