/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:58:41 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/07 13:31:23 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
#include "Animal.hpp"

class Cat : public Animal
{
private:

protected:

public:
    
    Cat();
    Cat( Cat const & src );
    ~Cat();
    
    Cat & operator=( Cat const & rhs );

    void makeSound( void ) const;
};

std::ostream & operator<<( std::ostream & out, Cat const & rhs );

#endif