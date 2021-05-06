/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedison <tedison@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 11:12:41 by tedison           #+#    #+#             */
/*   Updated: 2021/04/21 11:49:31 by tedison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	treat_char(va_list arg_list, t_flags *flags)
{
	int	value;
	int	i;

	i = 0;
	value = va_arg(arg_list, int);
	if ((*flags).minus)
		i += ft_putchar(value);
	while (flags->min_width-- > 1)
		i += ft_putchar(' ');
	if (!flags->minus)
		i += ft_putchar(value);
	return (i);
}

int	treat_string(va_list arg_list, t_flags *flags)
{
	char	*value;
	int		copy_min_width;
	int		length;
	int		i;

	i = 0;
	value = va_arg(arg_list, char *);
	if (value == NULL)
		value = "(null)";
	length = ft_strlen(value);
	if (flags->period && flags->max_width < length)
		length = flags->max_width;
	if (flags->min_width < length)
		flags->min_width = length;
	if (flags->min_width == 0)
		flags->min_width = length;
	copy_min_width = flags->min_width;
	if (flags->minus)
		i += ft_putstr(value, length);
	while (copy_min_width-- > length)
		i += ft_putchar(' ');
	if (!flags->minus)
		i += ft_putstr(value, length);
	return (i);
}

int	pointer_min_width(va_list arg_list, t_flags *flags, int i, int length)
{
	while (flags->min_width > length)
	{
		i += ft_putchar(' ');
		flags->min_width--;
	}
	return (i);
}

int	treat_pointer(va_list arg_list, t_flags *flags)
{
	unsigned long long int	value;
	int						length;
	int						i;

	i = 0;
	value = (unsigned long long int) va_arg(arg_list, void *);
	length = chars_to_malloc_pointer(value, 16) + 2;
	if (value == 0 && flags->period)
		length = 2;
	if ((*flags).minus)
	{
		i += ft_putstr("0x", 2);
		if (!(value == 0 && flags->period == 1 && flags->max_width == 0))
			ft_putnbr_base_unsigned(value, "0123456789abcdef", &i);
	}
	i = pointer_min_width(arg_list, flags, i, length);
	if (!flags->minus)
	{
		i += ft_putstr("0x", 2);
		if (value == 0 && flags->period == 1 && flags->max_width == 0)
			return (i);
		ft_putnbr_base_unsigned(value, "0123456789abcdef", &i);
	}
	return (i);
}
