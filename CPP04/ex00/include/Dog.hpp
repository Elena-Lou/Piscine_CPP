/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:59:26 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/07 13:31:18 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
#include "Animal.hpp"

class Dog : public Animal
{
private:

protected:

    
public:

    Dog();
    Dog( Dog const & src );
    ~Dog();

    Dog & operator=( Dog const & rhs );

    void makeSound( void ) const;
};

#endif