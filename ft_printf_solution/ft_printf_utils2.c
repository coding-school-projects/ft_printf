/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchennia <pchennia@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:01:25 by pchennia          #+#    #+#             */
/*   Updated: 2023/11/27 12:43:24 by pchennia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unbrlen(unsigned int n)
{
	unsigned int	nbr;
	int				len;

	nbr = n;
	len = 0;
	if (n == 0)
		len = 1;
	while (nbr != 0)
	{
		len++;
		nbr = nbr / 10;
	}
	return (len);
}

int	ft_found_u(unsigned int nbr)
{
	int				result;
	unsigned int	n;
	int				len;
	char			str[11];

	len = ft_unbrlen(nbr);
	n = nbr;
	str[len--] = '\0';
	while (len != 0)
	{
		str[len--] = n % 10 + '0';
		n = n / 10;
	}
	str[len] = n % 10 + '0';
	result = ft_found_s(str);
	return (result);
}

int	ft_found_smallx(unsigned int n)
{
	int				result;
	int				i;
	unsigned int	nbr;
	char			hex[9];

	nbr = n;
	i = 7;
	hex[8] = '\0';
	if (nbr == 0)
		hex[i--] = '0';
	while (nbr != 0)
	{
		if (nbr % 16 > 9)
			hex[i--] = nbr % 16 + 87;
		else
			hex[i--] = nbr % 16 + '0';
		nbr /= 16;
	}
	i++;
	result = ft_found_s(&hex[i]);
	return (result);
}

int	ft_found_bigx(unsigned int n)
{
	int				result;
	int				i;
	unsigned int	nbr;
	char			hex[9];

	nbr = n;
	i = 7;
	hex[8] = '\0';
	if (nbr == 0)
		hex[i--] = '0';
	while (nbr != 0)
	{
		if (nbr % 16 > 9)
			hex[i--] = nbr % 16 + 55;
		else
			hex[i--] = nbr % 16 + '0';
		nbr /= 16;
	}
	i++;
	result = ft_found_s(&hex[i]);
	return (result);
}

int	ft_found_p(unsigned long n)
{
	int		result;
	int		i;
	int		temp;
	char	hex[17];

	result = ft_found_s("0x");
	if (result != 2)
		return (-1);
	i = 15;
	hex[16] = '\0';
	if (n == 0)
		hex[i--] = '0';
	while (n != 0)
	{
		if (n % 16 > 9)
			hex[i--] = n % 16 + 87;
		else
			hex[i--] = n % 16 + '0';
		n /= 16;
	}
	temp = ft_found_s(&hex[++i]);
	if (temp == -1)
		return (-1);
	result += temp;
	return (result);
}
