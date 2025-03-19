/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 22:36:29 by tialbert          #+#    #+#             */
/*   Updated: 2025/03/18 21:44:52 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
	public:
		Fixed( void );
		Fixed( int const value );
		Fixed( float const value );
		~Fixed( void );
		Fixed( const Fixed &fixed );
		Fixed				&operator= ( const Fixed &fixed );
		bool				operator> ( const Fixed &fixed );
		bool				operator< ( const Fixed &fixed );
		bool				operator>= ( const Fixed &fixed );
		bool				operator<= ( const Fixed &fixed );
		bool				operator== ( const Fixed &fixed );
		bool				operator!= ( const Fixed &fixed );
		Fixed				operator+ ( const Fixed &fixed );
		Fixed				operator- ( const Fixed &fixed );
		Fixed				operator* ( const Fixed &fixed );
		Fixed				operator/ ( const Fixed &fixed );
		Fixed				&operator-- ( void );
		Fixed				&operator++ ( void );
		Fixed				operator-- ( int );
		Fixed				operator++ ( int );
		static Fixed		&min( Fixed &fixed1, Fixed &fixed2 );
		static const Fixed	&min( const Fixed &fixed1, const Fixed &fixed2 );
		static Fixed		&max( Fixed &fixed1, Fixed &fixed2 );
		static const Fixed	&max( const Fixed &fixed1, const Fixed &fixed2 );
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;

	private:
		int					_nb;
		static const int	_fracBits;
};

std::ostream	&operator<< ( std::ostream &output, const Fixed &fixed );

#endif
