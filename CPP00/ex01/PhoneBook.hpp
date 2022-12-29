/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:28:43 by elouisia          #+#    #+#             */
/*   Updated: 2022/11/13 16:38:41 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
#include "Contact.hpp"

class PhoneBook {
    
private:
    
    Contact _contact[8];

public:

    PhoneBook( void );
    ~PhoneBook( void );
  
    void	get_contact( void );
    int		set_contact(int);
    
    void    display_contact(int index) const;
    void    display_contact(std::string data) const;
    int     ft_check_index(std::string index);

};
#endif