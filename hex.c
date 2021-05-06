/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedison <tedison@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 11:18:44 by tedison           #+#    #+#             */
/*   Updated: 2021/04/21 11:44:59 by tedison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_max_width_hex(long long int value, int length, t_flags *flags)
{
	int	i;
	int	zero_number;

	i = 0;
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

int	hex_minus(long long int value, int length, t_flags *flags, int h)
{
	int	i;

	i = 0;
	if (value < 0)
		i += ft_putchar('-');
	i += print_max_width(value, length, flags);
	if (h == 0)
		ft_putnbr_base(value, "0123456789abcdef", &i);
	else
		ft_putnbr_base(value, "0123456789ABCDEF", &i);
	return (i);
}

int	spaces_hex(long long int value, int length, t_flags *flags, int h)
{
	int		i;
	char	c;

	i = 0;
	c = ' ';
	if (flags->zero && !flags->minus && !flags->period)
		c = '0';
	if (flags->minus)
	{	
		i += hex_minus(value, length, flags, h);
		i += min_width(value, c, length, flags);
		return (i);
	}
	if (c == '0' && value < 0)
		i += ft_putchar('-');
	i += min_width(value, c, length, flags);
	if (c == ' ' && value < 0)
		i += ft_putchar('-');
	i += print_max_width(value, length, flags);
	if (h == 0)
		ft_putnbr_base(value, "0123456789abcdef", &i);
	else
		ft_putnbr_base(value, "0123456789ABCDEF", &i);
	return (i);
}

int	treat_hexa_low(va_list arg_list, t_flags *flags)
{	
	unsigned int	value;
	int				length;

	value = va_arg(arg_list, unsigned int);
	length = chars_to_malloc(value, 16);
	if (value == 0 && flags->period == 1 && flags->max_width == 0)
		return (treat_period_value_zero(flags));
	if (flags->max_width >= flags->min_width)
		return (zeroes_hex(value, length, flags, 0));
	else
		return (spaces_hex(value, length, flags, 0));
}

int	treat_hexa_up(va_list arg_list, t_flags *flags)
{
	unsigned int	value;
	int				length;

	value = va_arg(arg_list, unsigned int);
	length = chars_to_malloc(value, 16);
	if (value == 0 && flags->period == 1 && flags->max_width == 0)
		return (treat_period_value_zero(flags));
	if (flags->max_width >= flags->min_width)
		return (zeroes_hex(value, length, flags, 1));
	else
		return (spaces_hex(value, length, flags, 1));
}
