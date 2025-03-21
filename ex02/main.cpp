/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 22:35:55 by tialbert          #+#    #+#             */
/*   Updated: 2025/03/21 23:32:02 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/include.hpp"

int main(void) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	bool	bol;

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	std::cout << std::endl;

	bol = a > b;
	std::cout << "0.0078 > 10.10: " << bol << std::endl;
	bol = a < b;
	std::cout << "0.0078 < 10.10: " << bol << std::endl;

	Fixed c(20);
	Fixed const d(20);
	bol = c > a;
	std::cout << "20 > 0.0078: " << bol << std::endl;
	bol = c < a;
	std::cout << "20 < 0.0078: " << bol << std::endl;

	bol = c <= d;
	std::cout << "20 <= 20: " << bol << std::endl;

	bol = c >= d;
	std::cout << "20 >= 20: " << bol << std::endl;

	bol = c <= b;
	std::cout << "20 <= 10.10: " << bol << std::endl;

	bol = c >= b;
	std::cout << "20 >= 10.10: " << bol << std::endl;

	bol = c == d;
	std::cout << "20 == 20: " << bol << std::endl;

	bol = c == b;
	std::cout << "20 == 10.10: " << bol << std::endl;

	bol = c != d;
	std::cout << "20 != 20: " << bol << std::endl;

	bol = c != b;
	std::cout << "20 != 10.10: " << bol << std::endl;

	std::cout << "20 + 20: " << (c + d) << std::endl;
	std::cout << "20 - 20: " << (c - d) << std::endl;
	std::cout << "20 * 20: " << (c * d) << std::endl;
	std::cout << "20 / 20: " << (c / d) << std::endl;


	std::cout << "Post-decrement: " << a-- << std::endl;
	std::cout << "Value after: " << a << std::endl;
	std::cout << "Pre-decrement: " << --a << std::endl;

	std::cout << "max const(20, 10.10): " << Fixed::max( d, b ) << std::endl;
	std::cout << "min const(20, 10.10): " << Fixed::min( d, b ) << std::endl;

	std::cout << "max(20, 0): " << Fixed::max( c, a ) << std::endl;
	std::cout << "min(20, 0): " << Fixed::min( c, a ) << std::endl;

	Fixed e;
	std::cout << "20 / 0: " << (c / e) << std::endl;
	return 0;

}
