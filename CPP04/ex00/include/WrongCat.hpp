/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 17:00:39 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/04 15:11:52 by elouisia         ###   ########.fr       */
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

    std::string type;

public:
    
    WrongCat();
    WrongCat( WrongCat const & src );
    ~WrongCat();
    
    WrongCat & operator=( WrongCat const & rhs );

    std::string getType( void ) const ;
    void makeSound( void ) const;
};

std::ostream & operator<<( std::ostream & out, WrongCat const & rhs );

#endif