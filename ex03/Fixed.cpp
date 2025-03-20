/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 22:36:15 by tialbert          #+#    #+#             */
/*   Updated: 2025/03/20 22:09:41 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Include/include.hpp"

const int Fixed::_fracBits = 8;

Fixed::Fixed( void ) {
	setRawBits(0);
}

Fixed::Fixed( int const value ) {
	setRawBits(value * pow(2, _fracBits));
}

Fixed::Fixed( float const value ) {
	setRawBits(roundf(value * pow(2, _fracBits)));
}

Fixed::~Fixed( void ) {
}

Fixed::Fixed( const Fixed &fixed ) {
	*this = fixed;
}

Fixed	&Fixed::operator= ( const Fixed &fixed ) {
	setRawBits(fixed.getRawBits());
	return (*this);
}

bool	Fixed::operator> ( const Fixed &fixed ) {
	return (this->toFloat() > fixed.toFloat());
}

bool	Fixed::operator< ( const Fixed &fixed ) {
	return (this->toFloat() < fixed.toFloat());
}

bool	Fixed::operator>= ( const Fixed &fixed ) {
	return (this->toFloat() >= fixed.toFloat());
}

bool	Fixed::operator<= ( const Fixed &fixed ) {
	return (this->toFloat() <= fixed.toFloat());
}

bool	Fixed::operator== ( const Fixed &fixed ) {
	return (this->toFloat() == fixed.toFloat());
}

bool	Fixed::operator!= ( const Fixed &fixed ) {
	return (this->toFloat() != fixed.toFloat());
}

Fixed	Fixed::operator+ ( const Fixed &fixed ) {
	float	result;

	result = this->toFloat() + fixed.toFloat();
	Fixed	temp(result);
	return (temp);
}

Fixed	Fixed::operator- ( const Fixed &fixed ) {
	float	result;

	result = this->toFloat() - fixed.toFloat();
	Fixed	temp(result);
	return (temp);
}

Fixed	Fixed::operator* ( const Fixed &fixed ) {
	float	result;

	result = this->toFloat() * fixed.toFloat();
	Fixed	temp(result);
	return (temp);
}

Fixed	Fixed::operator/ ( const Fixed &fixed ) {
	float	result;

	if (fixed.toFloat() == 0) {
		std::cout << "division for 0" << std::endl;
		exit(1);
	}
	result = this->toFloat() / fixed.toFloat();
	Fixed	temp(result);
	return (temp);
}

Fixed	&Fixed::operator-- ( void ) {
	_nb--;
	return (*this);
}

Fixed	&Fixed::operator++ ( void ) {
	_nb++;
	return (*this);
}

Fixed	Fixed::operator-- ( int ) {
	Fixed	temp = *this;

	--_nb;
	return (temp);
}

Fixed	Fixed::operator++ ( int ) {
	Fixed	temp = *this;

	++_nb;
	return (temp);
}

Fixed	&Fixed::min( Fixed &fixed1, Fixed &fixed2 ) {
	if (fixed1 <= fixed2)
		return (fixed1);
	else
		return (fixed2);
}

const Fixed	&Fixed::min( const Fixed &fixed1, const Fixed &fixed2 ) {
	if (fixed1.toFloat() <= fixed2.toFloat())
		return (fixed1);
	else
		return (fixed2);
}

Fixed	&Fixed::max( Fixed &fixed1, Fixed &fixed2 ) {
	if (fixed1 >= fixed2)
		return (fixed1);
	else
		return (fixed2);
}

const Fixed	&Fixed::max( const Fixed &fixed1, const Fixed &fixed2 ) {
	if (fixed1.toFloat() >= fixed2.toFloat())
		return (fixed1);
	else
		return (fixed2);
}

int		Fixed::getRawBits( void ) const {
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
