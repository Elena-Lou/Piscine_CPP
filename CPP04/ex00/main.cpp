/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:37:04 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/03 12:41:37 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "iostream"

int main ( void ) {

    Animal* Praline = new Cat();
    Animal* Zako = new Dog();
    //Animal* Tyra = new Animal();
    Dog    Bob;
    Dog		Marcel(Bob);
	Dog		d;

	Cat 	Pral;
	Cat		Minus(Pral);
	Animal  Tyra;
	Animal  Nosaure(Tyra);
	d = Bob;
   

    std::cout << Praline->getType() << std::endl;
    std::cout << Zako->getType() << std::endl;
    //std::cout << Tyra->getType() << std::endl;
    std::cout << Bob << std::endl;
	std::cout << "marcel : " << Marcel.getType() << " !" << std::endl;
	std::cout << "d : " << d << " !" << std::endl;
	std::cout << "minus : " << Minus << std::endl;
	std::cout << Nosaure << std::endl;

    
    Praline->makeSound();
    Zako->makeSound();
    //Tyra->makeSound();
    Bob.makeSound();
	Marcel.makeSound();
	d.makeSound();


    delete Praline;
    delete Zako;
    //delete Tyra;


    return 0;
    
}