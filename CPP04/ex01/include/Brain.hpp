/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 15:48:25 by elouisia          #+#    #+#             */
/*   Updated: 2022/12/06 14:55:23 by elouisia         ###   ########.fr       */
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
	~Brain();

	void		setIdeas( std::string ideas );
	void 		setIdea( std::string idea, int i );
	std::string getIdea( int i ) const;
	
	
	
};


#endif