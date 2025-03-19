/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 21:25:04 by tialbert          #+#    #+#             */
/*   Updated: 2025/03/19 21:43:00 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/include.hpp"

Point::Point( void ) {
	Fixed	x(0);
	Fixed	y(0);

	_x = x;
	_y = y;
	std::cout << "Point void constructor called" << std::endl;
}

Point::Point( const float x, const float y ) {
	Fixed	fixed_x(x);
	Fixed	fixed_y(y);

	_x = fixed_x;
	_y = fixed_y;
	std::cout << "Point float constructor called" << std::endl;
}

Point::~Point( void ) {
	std::cout << "Point destructor called" << std::endl;
}

Point::Point( const Point &point ) {
	std::cout << "Point copy constructor called" << std::endl;
	*this = point;
}

Point	&Point::operator= ( const Point &point ) {
	std::cout << "Point copy assignment operator called" << std::endl;
	setX(point.getX());
	setY(point.getY());

	return (*this);
}

void	Point::setX( Fixed const &fixed ) {
	_x = fixed;
}

void	Point::setY( Fixed const &fixed ) {
	_y = fixed;
}

Fixed	Point::getX( void ) const {
	return (_x);
}

Fixed	Point::getY( void ) const {
	return (_y);
}
