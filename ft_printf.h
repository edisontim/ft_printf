/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedison <tedison@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 10:26:50 by tedison           #+#    #+#             */
/*   Updated: 2021/04/21 11:45:57 by tedison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
typedef struct s_flags
{
	int	minus;
	int	zero;
	int	min_width;
	int	period;
	int	max_width;
}				t_flags;
void	ft_bzero(void *s, size_t n);
void	ft_putnbr_base(long long int nb, char *base, int *i);
size_t	ft_strlen(const char *s);
int		ft_printf(const char *s, ...);
void	ft_putnbr_base_unsigned(unsigned long long int nb, char *base, int *i);
int		decimal_spaces(long long int value, int length, t_flags *flags);
int		treat_decimal(va_list arg_list, t_flags *flags);
int		treat_unsigned(va_list arg_list, t_flags *flags);
int		zeroes_hex(long long int value, int length, t_flags *flags, int h);
int		min_width_hex(long long int value, char c, int length, t_flags *flags);
int		treat_period_value_zero(t_flags *flags);
int		decimal_zeroes(long long int value, int length, t_flags *flags);
int		min_width(long long int value, char c, int length, t_flags *flags);
int		print_max_width(long long int value, int length, t_flags *flags);
int		decimal_spaces_minus(long long int value, int length, t_flags *flags);
int		treat_param(va_list arg_list, const char *s, int *printed);
int		chars_to_malloc(long long int nbr, int base);
int		chars_to_malloc_pointer(unsigned long long int nbr, int base);
int		ft_putchar(char c);
int		ft_putstr(char *s, int len);
int		is_valid(char *base);
int		is_valid_unsigned(char *base);
void	ft_putnbr_base_unsigned(unsigned long long int nb, char *base, int *i);
int		print_max_width_hex(long long int value, int length, t_flags *flags);
int		hex_minus(long long int value, int length, t_flags *flags, int h);
int		spaces_hex(long long int value, int length, t_flags *flags, int h);
int		treat_hexa_low(va_list arg_list, t_flags *flags);
int		treat_hexa_up(va_list arg_list, t_flags *flags);
int		treat_pourcent(t_flags *flags);
int		determine_type(va_list arg_list, char *s, t_flags *flags);
int		treat_param_minus_zero(t_flags *flags, const char *s, int i);
int		param_min_width(t_flags *flags, const char *s, int i, va_list arg_list);
int		param_max_width(t_flags *flags, const char *s, int i, va_list arg_list);
int		treat_char(va_list arg_list, t_flags *flags);
int		treat_string(va_list arg_list, t_flags *flags);
int		pointer_min_width(va_list arg_list, t_flags *flags, int i, int length);
int		treat_pointer(va_list arg_list, t_flags *flags);

#endif
