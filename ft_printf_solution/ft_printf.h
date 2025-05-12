/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:43:34 by pchennia          #+#    #+#             */
/*   Updated: 2023/11/27 11:36:19 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_found_c(char c);
int	ft_found_s(char *str);
int	ft_found_d(int n);
int	ft_found_u(unsigned int n);
int	ft_found_d(int nbr);
int	ft_found_u(unsigned int nbr);
int	ft_found_smallx(unsigned int n);
int	ft_found_bigx(unsigned int n);
int	ft_found_p(unsigned long n);

#endif 
