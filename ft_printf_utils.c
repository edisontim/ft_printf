/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedison <tedison@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 11:09:33 by tedison           #+#    #+#             */
/*   Updated: 2021/04/21 11:22:02 by tedison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	chars_to_malloc(long long int nbr, int base)
{
	int	count;

	count = 0;
	if (nbr < 0)
		nbr = -nbr;
	while (nbr / base > 0)
	{
		nbr /= base;
		count++;
	}
	return (count + 1);
}

int	chars_to_malloc_pointer(unsigned long long int nbr, int base)
{
	int	count;

	count = 0;
	while (nbr / base > 0)
	{
		nbr /= base;
		count++;
	}
	return (count + 1);
}

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s, int len)
{
	int	i;

	i = 0;
	while (s[i] && i < len)
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}
