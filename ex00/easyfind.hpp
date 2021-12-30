/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 22:47:05 by kzennoun          #+#    #+#             */
/*   Updated: 2021/12/30 01:23:48 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <algorithm>
#include <vector>

template<typename T>
typename T::iterator easyfind(T & vec, int value)
{
	class ElementNotFoundException : public std::exception
	{
		const char* what() const throw()
		{
			return "easyfind error: couldn't find the element";
		}
	};

	typename T::iterator it;

	it = std::find(vec.begin(), vec.end(), value);
	if (it != vec.end())
		return it;
	else
		throw ElementNotFoundException();
}
