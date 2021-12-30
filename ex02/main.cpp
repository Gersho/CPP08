/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 05:24:21 by kzennoun          #+#    #+#             */
/*   Updated: 2021/12/30 06:57:16 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "mutantstack.hpp"
#include <iostream>

class Person
{
	public:

	Person(std::string name): _name(name){}

	std::string get_name() const
	{
		return _name;
	}

	void set_name(std::string name)
	{
		_name = name;
	}

	private:

	std::string _name;
};


std::ostream &	operator<<( std::ostream & o, Person const & i )
{

	o << i.get_name();

	return o;
}

int main()
{
	std::cout << "#### Subject Tests ####" << std::endl;
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "#### Custom Tests ####" << std::endl;

	MutantStack<Person> group;

	group.push(Person("Paul"));
	group.push(Person("Marie"));
	group.push(Person("Emmanuel"));
	group.push(Person("Valerie"));

	MutantStack<Person>::iterator it2 = group.begin();
	MutantStack<Person>::iterator ite2 = group.end();


	std::cout << "--- Print group ---" << std::endl;
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}
	std::cout << "--- Copy group to group2 ---" << std::endl;
	MutantStack<Person> group2(group);
	std::cout << "--- group[2].set_name(\"Bob\"); ---" << std::endl;
	group[2].set_name("Bob");

	std::cout << "--- Print group ---" << std::endl;
	it2 = group.begin();
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}
	std::cout << "--- Print group2 ---" << std::endl;
	it2 = group2.begin();
	ite2 = group2.end();
	while (it2 != ite2)
	{
		std::cout << *it2 << std::endl;
		++it2;
	}
	return 0;
}

/* 

Now that the appetizers are done, let’s do some disgusting stuff.

The std::stack container is VERY cool, but it’s one of the only STL containers that
is NOT iterable.
That’s too bad. But why be okay with it, when we can simply play
God and just butcher it to add some stuff we like?

You will splice this ability into the std::stack container, to repair this grave injustice.

Make a MutantStack class, that will be implemented in terms of a std::stack, and
offer all of its member functions, only it will also offer an iterator.

Below is an example of code, the output of which should be the same as if we replaced
the MutantStack with, for example, and std::list. You will of course provide tests for
all of this in your main function.

*/