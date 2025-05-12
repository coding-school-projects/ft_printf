/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:42:49 by pchennia          #+#    #+#             */
/*   Updated: 2023/11/27 11:33:42 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	ft_found(const char c, va_list a)
{
	int	result;

	if (c == 'c')
		result = ft_found_c(va_arg(a, int));
	else if (c == 's')
		result = ft_found_s(va_arg(a, char *));
	else if (c == 'p')
		result = ft_found_p(va_arg(a, unsigned long));
	else if (c == 'd' || c == 'i')
		result = ft_found_d(va_arg(a, int));
	else if (c == 'u')
		result = ft_found_u(va_arg(a, unsigned int));
	else if (c == 'x')
		result = ft_found_smallx(va_arg(a, unsigned int));
	else if (c == 'X')
		result = ft_found_bigx(va_arg(a, unsigned int));
	else if (c == '%')
		result = write(1, "%", 1);
	else
		result = -1;
	return (result);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		result;
	int		temp;

	va_start(args, format);
	result = 0;
	while (*format != '\0')
	{
		temp = 0;
		if (*format == '%' && *++format != '\0')
			temp = ft_found(*format++, args);
		else if (*format != '\0')
			temp = write(1, &*format++, 1);
		if (temp == -1)
		{
			va_end(args);
			return (-1);
		}
		result += temp;
	}
	va_end(args);
	return (result);
}
