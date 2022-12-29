/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:58:41 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/07 14:27:14 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{

private:

    Brain* brain;

protected:

public:
    
    Cat();
    Cat( Cat const & src );
    ~Cat();
    
    Cat & operator=( Cat const & rhs );

    void 			makeSound( void ) const;

    void			setIdeas( std::string const & ideas );
	void 			setIdea( std::string const & idea, int i );
    std::string		getIdea( int i ) const;
};

std::ostream & operator<<( std::ostream & out, Cat const & rhs );

#endif