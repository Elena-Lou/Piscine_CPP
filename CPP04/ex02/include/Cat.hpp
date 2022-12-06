/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 16:58:41 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/06 17:10:54 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{

private:

    Brain* brain;

protected:

    std::string type;

public:
    
    Cat();
    Cat( Cat const & src );
    ~Cat();
    
    Cat & operator=( Cat const & rhs );

    void 			makeSound( void ) const;
    std::string 	getType( void ) const ;

    void			setIdeas( std::string ideas );
	void 			setIdea( std::string idea, int i );
    std::string		getIdea( int i ) const;
};

std::ostream & operator<<( std::ostream & out, Cat const & rhs );

#endif