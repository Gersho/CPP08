/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 22:47:57 by kzennoun          #+#    #+#             */
/*   Updated: 2021/12/29 23:28:20 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <algorithm>
#include <iostream>
#include <vector>

int main(void)
{
	std::vector<int> test;
	test.push_back(-5);
	test.push_back(42);
	test.push_back(3);
	test.push_back(8);
	test.push_back(72);

	try
	{
		std::cout << easyfind(test, 42) << std::endl;
		std::cout << easyfind(test, 43) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}

/* 

An easy one to start off on the right foot...

Make a template function called easyfind, 
	templated on a type T
	 that takes a T
	and an int.

Assume the T is a container of int,
 and find the first occurrence of the second parameter in the first parameter.

If it can’t be found, handle the error either using an exception or using an error return
value. Take ideas from how standard containers work.

Of course, you will provide a main function that tests it thoroughly.

*/