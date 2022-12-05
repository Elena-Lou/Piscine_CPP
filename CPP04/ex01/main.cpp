/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:37:04 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/05 17:43:16 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "iostream"

int main ( void ) {

    // Animal* Praline = new Cat();
    // Animal* Tyra = new Dog();
    // Animal* Paquerette = new Animal();

    Dog     Melba;

    // std::cout << Praline->getType() << std::endl;
    // std::cout << Tyra->getType() << std::endl;
    // std::cout << Paquerette->getType() << std::endl;
    
    std::cout << Melba.getIdea(0) << std::endl;

    // Praline->makeSound();
    // Tyra->makeSound();
    // Paquerette->makeSound();
    Melba.makeSound();

    for ( int i = 0; i < 10; i++)
    {
        Melba.getBrain()->setIdea("Alex", i);
        std::cout << "Melba " << Melba.getIdea(i) << std::endl;
    }
    
    Dog Nosaure(Melba);
    Nosaure.getBrain()->setIdea("Elena", 0);
    std::cout << "Melba : " << Melba.getIdea(0) << std::endl;
    std::cout << "Nosaure : " << Nosaure.getIdea(0) << std::endl;

    // delete Praline;
    // delete Paquerette;;
    // delete Tyra;
		
    return 0;
}