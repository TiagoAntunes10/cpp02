/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 22:36:29 by tialbert          #+#    #+#             */
/*   Updated: 2025/03/12 22:41:57 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {
	public:
		Fixed( void );
		~Fixed( void );
		int		getRawBits( void ) const;
		void	setRawBits( int const raw );

	private:
		int					nb;
		static const int	frac_bits;
};

#endif
