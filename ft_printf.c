/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedison <tedison@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 17:54:03 by tedison           #+#    #+#             */
/*   Updated: 2021/04/21 11:23:10 by tedison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	treat_param(va_list arg_list, const char *s, int *printed)
{
	int		i;
	t_flags	flags;

	ft_bzero((void *)&flags, sizeof(flags));
	i = 1;
	i = treat_param_minus_zero(&flags, s, i);
	i = param_min_width(&flags, s, i, arg_list);
	if (s[i] == '.')
	{
		flags.period = 1;
		i++;
	}
	i = param_max_width(&flags, s, i, arg_list);
	if (flags.min_width < 0)
	{
		flags.min_width *= -1;
		flags.minus = 1;
	}
	if (flags.max_width < 0)
	{
		flags.max_width = 0;
		flags.period = 0;
	}
	*printed += determine_type(arg_list, (char *)&s[i], &flags);
	return (i);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	va_list	arg_list;
	int		printed;

	printed = 0;
	va_start(arg_list, s);
	i = 0;
	while (s[i])
	{
		if (s[i] == '%')
		{
			i += treat_param(arg_list, &s[i], &printed);
		}
		else
			printed += ft_putchar(s[i]);
		i++;
	}
	va_end(arg_list);
	return (printed);
}
