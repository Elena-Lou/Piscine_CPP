/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 15:48:25 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/07 14:25:08 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
#include <string>

class Brain {

private:

	std::string ideas[100];

protected:

public:

	Brain();
	Brain( Brain const & src );
	~Brain();
	
	Brain & operator=( Brain const & rhs );

	void		setIdeas( std::string const & ideas );
	void 		setIdea( std::string const & idea, int i );
	std::string getIdea( int i ) const;
	
	
	
};


#endif