/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 21:26:05 by tialbert          #+#    #+#             */
/*   Updated: 2025/03/19 22:17:17 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/include.hpp"

static Fixed	*calc_area( Point const a, Point const b, Point const c ) {
	Fixed	result((a.getX()*(b.getY() - c.getY()) + b.getX()*(c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())) / 2);
	Fixed	*area;

	area = new (std::nothrow) Fixed(result);

	return (area);
}

static Fixed	*calc_point_area( Point const a, Point const b, Point const c, Point const point ) {
	Fixed	*point_area1;
	Fixed	*point_area2;
	Fixed	*point_area3;
	Fixed	*total;

	point_area1 = calc_area(a, b, point);
	point_area2 = calc_area(a, c, point);
	point_area3 = calc_area(b, c, point);

	const Fixed	result(*point_area1 + *point_area2 + *point_area3);

	delete point_area1;
	delete point_area2;
	delete point_area3;

	total = new (std::nothrow) Fixed(result);
	return (total);
}

bool	bsp( Point const a, Point const b, Point const c, Point const point) {
	Fixed	*tri_area;
	Fixed	*total_area;

	tri_area = calc_area(a, b, c);
	total_area = calc_point_area(a, b, c, point);

	if (tri_area == total_area) {
		delete total_area;
		delete tri_area;
		return (true);
	}
	delete total_area;
	delete tri_area;
	return (false);
}
