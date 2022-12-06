/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:59:26 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/06 15:09:37 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
    
private:

    Brain* brain;
    
protected:

    std::string type;
    
public:

    Dog();
    Dog( Dog const & src );
    ~Dog();

    Dog & operator=( Dog const & rhs );

    void 			makeSound( void ) const;
    std::string 	getType ( void ) const;
	
	void			setIdeas( std::string ideas );
	void 			setIdea( std::string idea, int i );
    std::string		getIdea( int i ) const;
};

#endif