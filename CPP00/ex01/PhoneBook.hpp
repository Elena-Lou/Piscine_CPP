/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:28:43 by elouisia          #+#    #+#             */
/*   Updated: 2022/11/08 23:18:13 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
#include "Contact.hpp"

class PhoneBook {
    
private:
    
    Contact _contact[8];

public:

    PhoneBook(void);
    ~PhoneBook(void);
  
    void	get_contact(void) const;
    int		set_contact(int);
    
    void    display_contact(int) const;
    void    display_contact(std::string) const;

};
#endif