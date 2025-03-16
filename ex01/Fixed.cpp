/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 22:36:15 by tialbert          #+#    #+#             */
/*   Updated: 2025/03/16 21:16:26 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/include.hpp"

const int Fixed::_fracBits = 8;

Fixed::Fixed( void ) {
	std::cout << "Default constructor called" << std::endl;
	setRawBits(0);
}

Fixed::Fixed( int const value ) {
	std::cout << "Int constructor called" << std::endl;
	setRawBits(value * pow(2, _fracBits));
}

Fixed::Fixed( float const value ) {
	std::cout << "Float constructor called" << std::endl;
	setRawBits(roundf(value * pow(2, _fracBits)));
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed( const Fixed &fixed ) {
	std::cout << "Copy constructor called" << std::endl;
	*this = fixed;
}

Fixed	&Fixed::operator= ( const Fixed &fixed ) {
	std::cout << "Copy assignment operator called" << std::endl;
	setRawBits(fixed.getRawBits());
	return (*this);
}

int		Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (_nb);
}

void	Fixed::setRawBits( int const raw ) {
	_nb = raw;
}

float	Fixed::toFloat( void ) const {
	float	value;

	value = (float) _nb / (float) pow(2, _fracBits);
	return (value);
}

int		Fixed::toInt( void ) const {
	return (_nb / pow(2, _fracBits));
}

std::ostream	&operator<< ( std::ostream &output, const Fixed &fixed ) {
	output << fixed.toFloat();
	return (output);
}
