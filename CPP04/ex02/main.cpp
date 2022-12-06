/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:37:04 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/06 17:13:44 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "iostream"

int main ( void ) {

    AAnimal* Praline = new Cat();
    AAnimal* Melba = new Dog();
    // AAnimal* Paquerette = new AAnimal();

    std::cout << "\n---------------\n" << std::endl;

    std::cout << Praline->getType() << std::endl;
    std::cout << Melba->getType() << std::endl;
    // std::cout << Paquerette->getType() << std::endl;
    
    std::cout << "\n---------------\n" << std::endl;

    Praline->makeSound();
    Melba->makeSound();
    // Paquerette->makeSound();
    

    std::cout << "\n---------------\n" << std::endl;

    Dog     Tyra;
    
    Tyra.makeSound();

    std::cout << "Tyra-idea[0] : " << Tyra.getIdea(0) << std::endl;
    
    Tyra.setIdeas("Alex");
    std::cout << "Tyra-idea[0] : " << Tyra.getIdea(0) << std::endl;
    std::cout << "Tyra-idea[99] : " << Tyra.getIdea(99) << std::endl;
    std::cout << "Tyra-idea[100] : " << Tyra.getIdea(100) << std::endl;
    
    Dog Nosaure(Tyra);
    std::cout << "Nosaure : " << Nosaure.getIdea(0) << std::endl;
    Nosaure.setIdea("Elena", 0);
    std::cout << "Nosaure [0] : " << Nosaure.getIdea(0) << std::endl;
    std::cout << "Nosaure [10] :" << Nosaure.getIdea(10) << std::endl;
    std::cout << "Tyra : " << Tyra.getIdea(0) << std::endl;

    std::cout << "\n---------------\n" << std::endl;

    Cat     Toulouse;
    
    Toulouse.makeSound();

    std::cout << "Toulouse-idea[0] : " << Toulouse.getIdea(0) << std::endl;
    
    Toulouse.setIdeas("Scat");
    std::cout << "Toulouse-idea[0] : " << Toulouse.getIdea(0) << std::endl;
    std::cout << "Toulouse-idea[99] : " << Toulouse.getIdea(99) << std::endl;
    std::cout << "Toulouse-idea[100] : " << Toulouse.getIdea(100) << std::endl;
    
    Cat Berlioz(Toulouse);
    std::cout << "Berlioz : " << Berlioz.getIdea(0) << std::endl;
    Berlioz.setIdea("Cat", 0);
    std::cout << "Berlioz [0] : " << Berlioz.getIdea(0) << std::endl;
    std::cout << "Berlioz [10] :" << Berlioz.getIdea(10) << std::endl;
    std::cout << "Toulouse : " << Toulouse.getIdea(0) << std::endl;

    std::cout << "\n---------------\n" << std::endl;

    delete Praline;
    // delete Paquerette;;
    delete Melba;
		
    return 0;
}