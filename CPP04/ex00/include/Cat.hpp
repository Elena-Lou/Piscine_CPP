/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:58:41 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/03 11:43:57 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
#include "Animal.hpp"

class Cat : public Animal
{
private:

protected:

    std::string type;

public:
    
    Cat();
    Cat( Cat const & src );
    ~Cat();
    
    Cat & operator=( Cat const & rhs );

    std::string getType( void ) const ;
    void makeSound( void ) const;
};

std::ostream & operator<<( std::ostream & out, Cat const & rhs );

#endif