/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elouisia <elouisia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 17:04:34 by elouisia          #+#    #+#             */
/*   Updated: 2023/01/17 11:35:31 by elouisia         ###   ########.fr       */
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

	std::cout << std::boolalpha << "mstack is empty ? "<< mstack.empty() << std::endl;
	mstack.push(5);
	mstack.push(17);
	std::cout << "mstack is empty ? "<< mstack.empty() << std::endl;
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
	
	std::cout << "\nITERATOR\n" << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	
	std::cout << "\nREVERSE_ITERATOR\n" << std::endl;
	
	MutantStack<int>::reverse_iterator itmstackRev = mstack.rbegin();
	MutantStack<int>::reverse_iterator itemstackRev = mstack.rend();
	
	++itmstackRev;
	--itmstackRev;
	while (itmstackRev != itemstackRev)
	{
		std::cout << *itmstackRev << std::endl;
		++itmstackRev;
	}

	std::cout << "\nCONST_ITERATOR\n" << std::endl;
	
	MutantStack<int>::const_iterator itmstackConst = mstack.cbegin();
	MutantStack<int>::const_iterator itemstackConst = mstack.cend();
	
	++itmstackConst;
	--itmstackConst;
	while (itmstackConst != itemstackConst)
	{
		std::cout << *itmstackConst << std::endl;
		++itmstackConst;
	}

	std::cout << "\nCONST_REVERSE_ITERATOR\n" << std::endl;
	
	MutantStack<int>::const_reverse_iterator itmstackConstRev = mstack.crbegin();
	MutantStack<int>::const_reverse_iterator itemstackConstRev = mstack.crend();
	
	++itmstackConstRev;
	--itmstackConstRev;
	while (itmstackConstRev != itemstackConstRev)
	{
		std::cout << *itmstackConstRev << std::endl;
		++itmstackConstRev;
	}

	std::cout << "\n --- STD::STACK ---\n" << std::endl;
	std::stack<int> s(mstack);
	s.push(5);
	s.push(17);
	std::cout << "s.top() : " << s.top() << std::endl;
	std::cout << "s.size() : " << s.size() << std::endl;

	std::cout << "\n --- STD::LIST ---\n" << std::endl;

	std::list<int> mlist;
	mlist.push_back(5);
	mlist.push_back(17);
	std::cout << "mlist.back() : " << mlist.back() << std::endl;
	std::cout << "mlist.size() : " << mlist.size() << std::endl;

	mlist.pop_back();
	std::cout << "After pop_back - mlist.back() : " << mlist.back() << std::endl;

	std::cout << "mlist.size() : " << mlist.size() << std::endl;
	mlist.push_back(3);
	mlist.push_back(5);
	mlist.push_back(737);
	mlist.push_back(0);

	std::cout << "mlist.size() : " << mlist.size() << std::endl;
	
	std::cout << "\nITERATOR\n" << std::endl;
	std::list<int>::iterator itList = mlist.begin();
	std::list<int>::iterator iteList = mlist.end();
	
	++itList;
	--itList;
	while (itList != iteList)
	{
		std::cout << *itList << std::endl;
		++itList;
	}

	std::cout << "\nREVERSE_ITERATOR\n" << std::endl;

	std::list<int>::reverse_iterator itListRev = mlist.rbegin();
	std::list<int>::reverse_iterator iteListRev = mlist.rend();
	
	++itListRev;
	--itListRev;
	while (itListRev != iteListRev)
	{
		std::cout << *itListRev << std::endl;
		++itListRev;
	}

	return 0;
}