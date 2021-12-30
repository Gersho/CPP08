/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantstack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 05:24:24 by kzennoun          #+#    #+#             */
/*   Updated: 2021/12/30 06:53:14 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:

	typedef typename MutantStack::container_type::iterator iterator;

	MutantStack(): std::stack<T>() {}
	MutantStack(const MutantStack &src): std::stack<T>(src) {};
	~MutantStack() {}

	MutantStack &operator=(const MutantStack & rhs)
	{
		std::stack<T>::operator=(rhs);
	}

	T & operator[](const unsigned int & index)
	{
		return this->c[index];
	}

	typename MutantStack::container_type::iterator begin()
	{
		return this->c.begin(); //c is underlying container
	}

	typename MutantStack::container_type::iterator end()
	{
		return this->c.end(); //c is underlying container
	}

};


#endif /* ***************************************************** MUTANTSTACK_H */