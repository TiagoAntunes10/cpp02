/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 21:26:05 by tialbert          #+#    #+#             */
/*   Updated: 2025/03/21 22:32:10 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/include.hpp"

static Fixed	*calc_w1( Point const a, Point const b, Point const c, Point const point ) {
	Fixed	*w1;
	Fixed	num;
	Fixed	den;

	if (a.getY() != c.getY() && b.getX() != a.getX()) {
		num = a.getX() * (c.getY() - a.getY()) + (point.getY() - a.getY()) * (c.getX() - a.getX()) - point.getX() * (c.getY() - a.getY());
		den = (b.getY() - a.getY()) * (c.getX() - a.getX()) - (b.getX() - a.getX()) * (c.getY() - a.getY());
	}
	else {
		num = (point.getY() - a.getY()) * (c.getX() - a.getX()) - (point.getX() - a.getX()) * (c.getY() - a.getY());
		den = (b.getY() - a.getY()) * (c.getX() - a.getX()) - (b.getX() - a.getX()) * (c.getY() - a.getY());
	}

	if (den == (Fixed) 0) {
		std::cout << "Division by 0" << std::endl;
		return (NULL);
	}

	w1 = new (std::nothrow) Fixed(num / den);
	if (w1 == NULL)
		return (NULL);

	return (w1);
}

static Fixed	*calc_w2( Point const a, Point const b, Point const c, Point const point, Fixed w1 ) {
	Fixed	*w2;
	Fixed	num;
	Fixed	den;

	if (a.getY() != c.getY() && b.getX() != a.getX()) {
		num = point.getY() - a.getY() - w1 * (b.getY() - a.getY());
		den = c.getY() - a.getY();
	}
	else {
		num = point.getX() - a.getX() - w1 * (b.getX() - a.getX());
		den = c.getX() - a.getX();
	}

	if (den == (Fixed) 0) {
		std::cout << "Division by 0" << std::endl;
		return (NULL);
	}

	w2 = new (std::nothrow) Fixed(num / den);
	if (w2 == NULL)
		return (NULL);

	return (w2);
}

bool	bsp( Point const a, Point const b, Point const c, Point const point) {
	Fixed	*w1;
	Fixed	*w2;

	if ((Point) a == (Point) b || (Point) a == (Point) c || (Point) b == (Point) c) {
		std::cout << "Points a, b and c do not form a triangle" << std::endl;
		exit (1);
	}

	w1 = calc_w1(a, b, c, point);
	if (w1 == NULL) {
		std::cout << "Memory allocation error" << std::endl;
		exit(1);
	}

	w2 = calc_w2(a, b, c, point, *w1);
	if (w2 == NULL) {
		delete w1;
		std::cout << "Memory allocation error" << std::endl;
		exit(1);
	}

	if (*w1 > (Fixed) 0 && *w2 > (Fixed) 0 && (*w1 + *w2) < (Fixed) 1) {
		delete w1;
		delete w2;
		return (true);
	}

	delete w1;
	delete w2;
	return (false);
}
