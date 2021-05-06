/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedison <tedison@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 11:15:20 by tedison           #+#    #+#             */
/*   Updated: 2021/04/21 11:41:28 by tedison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	treat_period_value_zero(t_flags *flags)
{
	int	i;

	i = 0;
	if (flags->min_width == 0)
		return (0);
	while (flags->min_width > 0)
	{
		i += ft_putchar(' ');
		flags->min_width--;
	}
	return (i);
}

int	decimal_zeroes(long long int value, int length, t_flags *flags)
{
	int	i;

	i = 0;
	if (value < 0)
	{
		i += ft_putchar('-');
		value *= -1;
	}
	while (flags->max_width > length)
	{
		i += ft_putchar('0');
		flags->max_width--;
	}
	ft_putnbr_base(value, "0123456789", &i);
	return (i);
}

int	min_width(long long int value, char c, int length, t_flags *flags)
{
	int	i;
	int	zero_number;

	if (value < 0)
		length--;
	if (length > flags->max_width)
		flags->max_width = length;
	zero_number = flags->max_width - length;
	if (value < 0)
		length++;
	i = 0;
	while (flags->min_width > zero_number + length)
	{
		i += ft_putchar(c);
		flags->min_width--;
	}
	return (i);
}

int	print_max_width(long long int value, int length, t_flags *flags)
{
	int	i;
	int	zero_number;

	i = 0;
	if (value < 0)
		length--;
	if (length > flags->max_width)
		flags->max_width = length;
	zero_number = flags->max_width - length;
	while (zero_number > 0)
	{
		i += ft_putchar('0');
		zero_number--;
	}
	return (i);
}

int	decimal_spaces_minus(long long int value, int length, t_flags *flags)
{
	int	i;

	i = 0;
	if (value < 0)
		i += ft_putchar('-');
	i += print_max_width(value, length, flags);
	ft_putnbr_base(value, "0123456789", &i);
	return (i);
}
