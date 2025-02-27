/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lemercie <lemercie@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 17:31:30 by lemercie          #+#    #+#             */
/*   Updated: 2025/02/27 16:08:31 by lemercie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

void	copyTest(Character cha, Character tar)
{
	std::cout << "is it a deep copy?" << std::endl;
	cha.use(0, tar);
}

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());

	ICharacter* me = new Character("me");

	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	Character john("John");
	Character dave("Dave");
	Character bork("Borko");
	AMateria* mat = new Ice();
	AMateria* mat2 = new Cure();
	AMateria* mat3 = new Cure();
	AMateria* mat4 = new Cure();
	AMateria* mat5 = new Cure();
	std::cout << john.getName() << std::endl;
	std::cout << dave.getName() << std::endl;
	dave.equip(mat);
	dave.equip(mat2);
	dave.use(0, bork);
	dave.use(1, bork);
	john = dave;
	std::cout << john.getName() << std::endl;
	std::cout << dave.getName() << std::endl;
	dave.use(0, bork);
	dave.use(1, bork);

	copyTest(dave, bork);

	dave.equip(mat3);
	dave.equip(mat4);
	dave.use(0, bork);
	dave.equip(mat5);
	dave.use(0, bork); // old materia stays and is not overwritten

	delete bob;
	delete me;
	delete src;

	return (0);
}
