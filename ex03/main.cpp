/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 22:35:55 by tialbert          #+#    #+#             */
/*   Updated: 2025/03/21 22:44:15 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/include.hpp"

int main(void) {
	Point	a(0, 0);
	Point	b(0, -1);
	Point	c(-1, 0);

	Point	point(-0.2, -0.2);
	std::cout << "Point inside triangle: ";
	std::cout << bsp(a, b, c, point) << std::endl;

	Point	point2(0, 0);
	std::cout << "Point coincidental with a vertex of the triangle: ";
	std::cout << bsp(a, b, c, point2) << std::endl;

	Point	point3(-0.5, -0.5);
	std::cout << "Point over an edge of the triangle: ";
	std::cout << bsp(a, b, c, point3) << std::endl;

	Point	point4(1, 1);
	std::cout << "Point outside triangle: ";
	std::cout << bsp(a, b, c, point4) << std::endl;

	Point	a1(1, 1);
	Point	b1(1, 1);
	Point	c1(1, 1);
	std::cout << "Points a, b and c do not create a triangle: ";
	std::cout << bsp(a1, b1, c1, point4) << std::endl;

	return 0;
}
