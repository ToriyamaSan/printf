/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dle-fur <dle-fur@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:27:52 by dle-fur           #+#    #+#             */
/*   Updated: 2024/10/20 15:24:23 by dle-fur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdint.h> //peut etre pas besoin sur mac

# include <stdio.h>

int		ft_printf(const char *format, ...);
//utils//
void	print_s(char *str, int *count);
void	print_c(int c, int *count);
void	print_hex(unsigned int nb, int maj, int *count);
void	print_n(int nb, int *count);
void	print_u(unsigned int n, int *count);
void	print_p(uintptr_t ptr, int *count);

#endif