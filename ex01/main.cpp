/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 22:15:19 by kzennoun          #+#    #+#             */
/*   Updated: 2021/12/30 06:13:43 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

int main(void)
{
	std::cout << "##### PART 1 #####" << std::endl;
	Span sp = Span(5);
	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(72);
		sp.addNumber(11);
		sp.addNumber(11); // error  : is full
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "--- print sp ---" << std::endl;
	for (std::vector<int>::iterator it = sp.begin(); it != sp.end(); it++ )
	{
		std::cout << *it << std::endl;
	}

	Span sp2 = sp;
	Span sp3(sp);
	Span sp4(10);
	sp4.addNumber(1);

	std::cout << "--- print sp2 ---" << std::endl;
	for (std::vector<int>::iterator it = sp2.begin(); it != sp2.end(); it++ )
	{
		std::cout << *it << std::endl;
	}
	try
	{
		std::cout << "sp shortest: " << sp.shortestSpan() << std::endl;
		std::cout << "sp longest: " << sp.longestSpan() << std::endl;
		std::cout << "sp4 shortest: " << sp4.shortestSpan() << std::endl; //error no span
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "##### PART 2 #####" << std::endl;
	Span sp8(150000);
	std::vector<int> tmp(150000);

	srand(time(NULL));
	for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end(); it++ )
	{
		*it = rand();
	}

	try
	{
		sp8.addRange(tmp.begin(), tmp.end());
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	Span sp9(10);
	std::vector<int> tmp2(10);
	for (std::vector<int>::iterator it = tmp2.begin(); it != tmp2.end(); it++ )
	{
		*it = rand();
	}
	try
	{
		sp9.addRange(tmp2.begin(), tmp2.end());
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << "--- print tmp2 ---" << std::endl;
	for (std::vector<int>::iterator it = tmp2.begin(); it != tmp2.end(); it++ )
	{
		std::cout << *it << std::endl;
	}
	std::cout << "--- print sp9 ---" << std::endl;
	for (std::vector<int>::iterator it = sp9.begin(); it != sp9.end(); it++ )
	{
		std::cout << *it << std::endl;
	}
}

/*

Make a class in which you can store N ints.

 N will be an unsigned int, and will be
passed to the constructor as its only parameter.

This class will have a function to store a single number (addNumber), that will be used
to fill it. 
Attempting to add a new number if there are already N of them stored in the
object is an error and should result in an exception.

You will now make two functions, shortestSpan and longestSpan, that will find
out respectively the shortest and longest span between all the numbers contained in the
object, and return it.
 If there are no numbers stored, or only one, there is no span to
find, and you will throw an exception.

Below is a (way too short) example of a test main and its associated output. Of
course, your main will be way more thorough than this.
 You have to test at the very
least with 10000 numbers. 
More would be a good thing.
 It would also be very good if
you could add numbers by passing a range of iterators, which would avoid the annoyance
of making thousands of calls to addNumber...

*/