/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:04:34 by elouisia          #+#    #+#             */
/*   Updated: 2023/01/17 10:38:35 by elouisia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main ( void ) {
	
	std::cout << "\n--- CHECK FROM CONTAINER ---\n" << std::endl;
	
	MutantStack<char> iterable_stack;
	
	for (char letter = 'a'; letter <= 'z'; letter++)
		iterable_stack.push(letter);
	for (MutantStack<char>::iterator it = iterable_stack.begin(); it != iterable_stack.end(); it++)
	{
		std::cout << *it;
	}
	std::cout << std::endl;

	std::cout << "\n--- CHECK FROM SUBJECT ---\n" << std::endl;

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "mstack.top() : " << mstack.top() << std::endl;
	std::cout << "mstack.size() : " << mstack.size() << std::endl;

	mstack.pop();
	std::cout << "After pop - mstack.top() : " << mstack.top() << std::endl;

	std::cout << "mstack.size() : " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	std::cout << "mstack.size() : " << mstack.size() << std::endl;
	
	MutantStack<int>::iterator it = mstack.begin();
	std::cout << "mstack.begin() : " << *mstack.begin() << std::endl;
	MutantStack<int>::iterator ite = mstack.end();
	std::cout << "mstack.end() : " << *mstack.end() << std::endl;
	
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}

	
	std::stack<int> s(mstack);
	s.push(5);
	s.push(17);
	std::cout << "s.top() : " << s.top() << std::endl;
	std::cout << "s.size() : " << s.size() << std::endl;

	return 0;
}