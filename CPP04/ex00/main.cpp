/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:37:04 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/04 15:21:27 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "iostream"

int main ( void ) {

    Animal* Praline = new Cat();
    Animal* Tyra = new Dog();
    Animal* Paquerette = new Animal();

	WrongAnimal* Omalley = new WrongAnimal();
	WrongAnimal* Toulouse = new WrongCat();

    std::cout << Praline->getType() << std::endl;
    std::cout << Tyra->getType() << std::endl;
    std::cout << Paquerette->getType() << std::endl;
    std::cout << Omalley->getType() << std::endl;
    std::cout << Toulouse->getType() << std::endl;

    Praline->makeSound();
    Tyra->makeSound();
    Paquerette->makeSound();
    Omalley->makeSound();
    Toulouse->makeSound();

    delete Praline;
    delete Paquerette;;
    delete Tyra;
    delete Omalley;
    delete Toulouse;
		
    return 0;
}