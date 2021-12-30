/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 23:50:13 by kzennoun          #+#    #+#             */
/*   Updated: 2021/12/30 04:12:59 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"


/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Span::Span()
{
	_array = NULL;
}

Span::Span(unsigned int N)
{
	_array = new std::vector<int>(N);
	_currentlast = _array->begin();
}

Span::Span( const Span & src )
{
std::cout << "COPY CONSTRUCTOR" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Span::~Span()
{
	if (_array)
		delete _array;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Span &				Span::operator=( Span const & rhs )
{
	if ( this != &rhs )
	{
		if (_array)
			delete (_array);
std::cout << "OPERATOR =" << std::endl;
		_array = new std::vector<int>(rhs._array->size());
		_currentlast = rhs._currentlast;
		addRange(rhs._array->begin(), rhs._currentlast);
	}
	return *this;
}



/*
** --------------------------------- METHODS ----------------------------------
*/

void	Span::addNumber(int value)
{
	if (_currentlast == end())
		throw SpanFullException();
	else
	{
		*_currentlast = value;
		_currentlast++;
	}
}

void	Span::addRange(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
	for (std::vector<int>::iterator it = start; it != end; it++)
	{
		addNumber(*start);
	}
}

long		Span::shortestSpan() const
{
	long small = __LONG_MAX__;
	if ((_currentlast - begin()) < 2)
		throw NoSpanException();
	for (std::vector<int>::iterator i = begin(); i != _currentlast; i++)
	{
		for (std::vector<int>::iterator j = i + 1; j != _currentlast; j++)
		{
			long tmp;

			tmp = *i - *j;
			if (tmp < 0)
				tmp *= -1;
			if (tmp < small)
				small = tmp;
		}
	}
	return small;
}

long		Span::longestSpan() const
{
	if ((_currentlast - begin()) < 2)
		throw NoSpanException();
	return (*std::max_element(begin(), _currentlast) - *std::min_element(begin(), _currentlast));
}

std::vector<int>::iterator	Span::begin() const
{
	return _array->begin();
}

std::vector<int>::iterator	Span::end() const
{
	return _array->end();
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/*
** --------------------------------- EXCEPTIONS -------------------------------
*/


const char* Span::SpanFullException::what() const throw()
{
	return "Error: the span is full.";
}

const char* Span::NoSpanException::what() const throw()
{
	return "Error: there is no span to find.";
}

/* ************************************************************************** */