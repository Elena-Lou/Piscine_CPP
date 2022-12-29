/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:00:39 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/07 13:31:40 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
#include "WrongAnimal.hpp"
#include <string>
#include <iostream>

class WrongCat : public WrongAnimal
{
private:

protected:


public:
    
    WrongCat();
    WrongCat( WrongCat const & src );
    ~WrongCat();
    
    WrongCat & operator=( WrongCat const & rhs );

    void makeSound( void ) const;
};

std::ostream & operator<<( std::ostream & out, WrongCat const & rhs );

#endif