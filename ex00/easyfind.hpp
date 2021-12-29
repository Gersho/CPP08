/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 22:47:05 by kzennoun          #+#    #+#             */
/*   Updated: 2021/12/29 23:23:00 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <vector>

template<typename T>
int & easyfind(T & vec, int value)
{
	class ElementNotFoundException : public std::exception
	{
		const char* what() const throw()
		{
			return "easyfind error: couldn't find the element";
		}
	};

	std::vector<int>::iterator it;

	it = std::find(vec.begin(), vec.end(), value);
	if (it != vec.end())
		return *it;
	else
		throw ElementNotFoundException();
}
