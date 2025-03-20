/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 22:35:55 by tialbert          #+#    #+#             */
/*   Updated: 2025/03/20 22:14:42 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/include.hpp"

int main(void) {
	Point	a(0, 0);
	Point	b(1, 0);
	Point	c(0, 1);
	Point	point(0, 0.5);

	std::cout << bsp(a, b, c, point) << std::endl;
	return 0;
}
