/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:37:00 by pchennia          #+#    #+#             */
/*   Updated: 2023/11/28 10:09:22 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_found_c(char c)
{
	int	result;

	result = write(1, &c, 1);
	return (result);
}

int	ft_found_s(char *str)
{
	int	i;
	int	result;
	int	temp;

	i = 0;
	result = 0;
	if (str != 0)
	{
		while (str[i] != '\0')
		{
			temp = result;
			result += ft_found_c(str[i++]);
			if (result < temp)
				return (-1);
		}
		return (result);
	}
	return (ft_found_s("(null)"));
}

int	ft_nbrlen(int n)
{
	int	nbr;
	int	len;

	nbr = n;
	len = 0;
	if (n == 0)
		len = 1;
	while (nbr != 0)
	{
		len++;
		nbr = nbr / 10;
	}
	if (n < 0)
		len++;
	return (len);
}

int	ft_found_d(int nbr)
{
	int		result;
	int		n;
	int		len;
	char	str[12];

	len = ft_nbrlen(nbr);
	n = nbr;
	str[len--] = '\0';
	while (len != 0)
	{
		if (nbr < 0)
			str[len--] = '0' - n % 10;
		else
			str[len--] = n % 10 + '0';
		n = n / 10;
	}
	if (nbr < 0)
		str[len] = '-';
	else
		str[len] = n % 10 + '0';
	result = ft_found_s(str);
	return (result);
}
