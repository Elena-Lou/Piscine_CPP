/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 18:28:43 by elouisia          #+#    #+#             */
/*   Updated: 2022/11/08 21:29:49 by elouisia         ###   ########.fr       */
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
    int		set_contact(int i);
    void	get_contact(void) const;
    ~PhoneBook(void);
};
#endif