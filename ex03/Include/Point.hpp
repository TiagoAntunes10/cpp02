/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 21:17:41 by tialbert          #+#    #+#             */
/*   Updated: 2025/03/21 21:50:12 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "./Fixed.hpp"

class Point {
	public:
		Point( void );
		Point( const float x, const float y );
		~Point( void );
		Point( const Point &point );
		Point	&operator= ( const Point &point );
		bool	operator== ( const Point &point );
		void	setX( Fixed const &fixed );
		void	setY( Fixed const &fixed );
		Fixed	getX( void ) const;
		Fixed	getY( void ) const;

	private:
		Fixed	_x;
		Fixed	_y;
};

#endif
