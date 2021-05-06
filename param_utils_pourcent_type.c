/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_utils_pourcent_type.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedison <tedison@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 11:19:54 by tedison           #+#    #+#             */
/*   Updated: 2021/04/21 11:20:11 by tedison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	treat_pourcent(t_flags *flags)
{
	char	c;
	int		i;

	i = 0;
	c = ' ';
	if (flags->zero && !flags->minus)
		c = '0';
	if ((*flags).minus)
		i += ft_putchar('%');
	while (flags->min_width-- > 1)
		i += ft_putchar(c);
	if (!flags->minus)
		i += ft_putchar('%');
	return (i);
}

int	determine_type(va_list arg_list, char *s, t_flags *flags)
{
	if (s[0] == 'c')
		return (treat_char(arg_list, flags));
	if (s[0] == 's')
		return (treat_string(arg_list, flags));
	if (s[0] == 'p')
		return (treat_pointer(arg_list, flags));
	if (s[0] == 'd')
		return (treat_decimal(arg_list, flags));
	if (s[0] == 'i')
		return (treat_decimal(arg_list, flags));
	if (s[0] == 'u')
		return (treat_unsigned(arg_list, flags));
	if (s[0] == 'x')
		return (treat_hexa_low(arg_list, flags));
	if (s[0] == 'X')
		return (treat_hexa_up(arg_list, flags));
	if (s[0] == '%')
		return (treat_pourcent(flags));
	return (0);
}

int	treat_param_minus_zero(t_flags *flags, const char *s, int i)
{
	if (s[i] == '-' || s[i] == '0')
	{
		while (s[i] == '-' || s[i] == '0')
		{
			if (s[i] == '-')
				flags->minus++;
			if (s[i] == '0' && ((s[i + 1] >= '0' && s[i + 1] <= '9')
					|| s[i + 1] == '*'))
				flags->zero++;
			i++;
		}
		if (flags->minus)
			flags->minus = 1;
	}
	return (i);
}

int	param_min_width(t_flags *flags, const char *s, int i, va_list arg_list)
{
	if ((s[i] >= '0' && s[i] <= '9') || s[i] == '*')
	{
		if (s[i] == '*')
		{
			flags->min_width = va_arg(arg_list, int);
			i++;
		}
		else
		{
			while (s[i] >= '0' && s[i] <= '9')
			{
				flags->min_width += s[i++] - '0';
				if (s[i] >= '0' && s[i] <= '9')
					flags->min_width *= 10;
			}
		}
	}
	return (i);
}

int	param_max_width(t_flags *flags, const char *s, int i, va_list arg_list)
{
	if (((s[i] >= '0' && s[i] <= '9') || s[i] == '*') && flags->period)
	{
		if (s[i] == '*')
		{
			flags->max_width = va_arg(arg_list, int);
			i++;
		}
		else
		{
			while (s[i] >= '0' && s[i] <= '9')
			{
				flags->max_width += s[i++] - '0';
				if (s[i] >= '0' && s[i] <= '9')
					flags->max_width *= 10;
			}
		}
	}
	return (i);
}
