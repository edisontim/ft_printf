/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_unsigned_hex_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedison <tedison@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 11:17:14 by tedison           #+#    #+#             */
/*   Updated: 2021/04/21 11:40:52 by tedison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	decimal_spaces(long long int value, int length, t_flags *flags)
{
	int		i;
	char	c;

	i = 0;
	c = ' ';
	if (flags->zero && !flags->minus && !flags->period)
		c = '0';
	if (value < 0)
		length++;
	if (flags->minus)
	{
		i += decimal_spaces_minus(value, length, flags);
		i += min_width(value, c, length, flags);
		return (i);
	}
	if (c == '0' && value < 0)
		i += ft_putchar('-');
	i += min_width(value, c, length, flags);
	if (c == ' ' && value < 0)
		i += ft_putchar('-');
	i += print_max_width(value, length, flags);
	ft_putnbr_base(value, "0123456789", &i);
	return (i);
}

int	treat_decimal(va_list arg_list, t_flags *flags)
{
	long long int	value;
	int				length;

	value = va_arg(arg_list, int);
	length = chars_to_malloc(value, 10);
	if (value == 0 && flags->period == 1 && flags->max_width == 0)
		return (treat_period_value_zero(flags));
	if (flags->max_width >= flags->min_width)
		return (decimal_zeroes(value, length, flags));
	else
		return (decimal_spaces(value, length, flags));
}

int	treat_unsigned(va_list arg_list, t_flags *flags)
{
	long long int	value;
	int				length;

	value = va_arg(arg_list, unsigned int);
	length = chars_to_malloc(value, 10);
	if (value == 0 && flags->period == 1 && flags->max_width == 0)
		return (treat_period_value_zero(flags));
	if (flags->max_width >= flags->min_width)
		return (decimal_zeroes(value, length, flags));
	else
		return (decimal_spaces(value, length, flags));
}

int	zeroes_hex(long long int value, int length, t_flags *flags, int h)
{
	int	i;

	i = 0;
	while (flags->max_width > length)
	{
		i += ft_putchar('0');
		flags->max_width--;
	}
	if (h == 0)
		ft_putnbr_base(value, "0123456789abcdef", &i);
	else
		ft_putnbr_base(value, "0123456789ABCDEF", &i);
	return (i);
}

int	min_width_hex(long long int value, char c, int length, t_flags *flags)
{
	int	i;
	int	zero_number;

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
