/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:59:26 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/07 14:29:50 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
    
private:

    Brain* brain;
    
protected:
    
public:

    Dog();
    Dog( Dog const & src );
    ~Dog();

    Dog & operator=( Dog const & rhs );

    void 			makeSound( void ) const;
	
	void			setIdeas( std::string const & ideas );
	void 			setIdea( std::string const & idea, int i );
    std::string		getIdea( int i ) const;
};

#endif