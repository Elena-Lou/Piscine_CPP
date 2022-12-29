/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:57:36 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/07 13:32:47 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP
#include <string>

class AAnimal
{
    
private:

protected:

    std::string type;

public:

            AAnimal();
            AAnimal( AAnimal const & src );
    virtual ~AAnimal();
            
            AAnimal & operator=( AAnimal const & rhs );
    
    virtual void makeSound( void ) const = 0 ;
            std::string getType ( void ) const = 0 ;
    
};

std::ostream & operator<<( std::ostream & out, AAnimal const & rhs );

#endif