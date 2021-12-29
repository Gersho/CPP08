/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzennoun <kzennoun@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 22:15:19 by kzennoun          #+#    #+#             */
/*   Updated: 2021/12/29 22:15:29 by kzennoun         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/*

Make a class in which you can store N ints. N will be an unsigned int, and will be
passed to the constructor as its only parameter.
This class will have a function to store a single number (addNumber), that will be used
to fill it. Attempting to add a new number if there are already N of them stored in the
object is an error and should result in an exception.
You will now make two functions, shortestSpan and longestSpan, that will find
out respectively the shortest and longest span between all the numbers contained in the
object, and return it. If there are no numbers stored, or only one, there is no span to
find, and you will throw an exception.
Below is a (way too short) example of a test main and its associated output. Of
course, your main will be way more thorough than this. You have to test at the very
least with 10000 numbers. More would be a good thing. It would also be very good if
you could add numbers by passing a range of iterators, which would avoid the annoyance
of making thousands of calls to addNumber...

*/