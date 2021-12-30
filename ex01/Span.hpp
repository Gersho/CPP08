/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 23:50:09 by kzennoun          #+#    #+#             */
/*   Updated: 2021/12/30 03:35:05 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <iostream>
# include <algorithm>

class Span
{


	public:
	
	Span(unsigned int N);
	Span(const Span & src);
	Span	&operator=(const Span & rhs);
	~Span();

	void	addNumber(int value);
	void	addRange(std::vector<int>::iterator start, std::vector<int>::iterator end);
	long		shortestSpan() const;
	long		longestSpan() const;
	std::vector<int>::iterator	begin() const;
	std::vector<int>::iterator	end() const;

	class SpanFullException : public std::exception
	{
		const char* what() const throw();
	};
	class NoSpanException : public std::exception
	{
		const char* what() const throw();
	};

	private : 

	std::vector<int> * _array;
	std::vector<int>::iterator _currentlast;
	Span();
};


#endif /* ************************************************************ SPAN_H */