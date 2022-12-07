/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:57:36 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/07 13:30:36 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
#include <string>

class Animal
{
    
private:

protected:

    std::string type;

public:

            Animal();
            Animal( Animal const & src );
    virtual ~Animal();
            
            Animal & operator=( Animal const & rhs );
    
    virtual void makeSound( void ) const;
    std::string getType ( void ) const;
    
};

std::ostream & operator<<( std::ostream & out, Animal const & rhs );

#endif