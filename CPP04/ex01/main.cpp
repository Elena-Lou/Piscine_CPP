/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:37:04 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/04 15:57:32 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "iostream"

int main ( void ) {

    Animal* Praline = new Cat();
    Animal* Tyra = new Dog();
    Animal* Paquerette = new Animal();

    std::cout << Praline->getType() << std::endl;
    std::cout << Tyra->getType() << std::endl;
    std::cout << Paquerette->getType() << std::endl;

    Praline->makeSound();
    Tyra->makeSound();
    Paquerette->makeSound();

    delete Praline;
    delete Paquerette;;
    delete Tyra;
		
    return 0;
}