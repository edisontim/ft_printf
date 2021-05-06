/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 18:48:37 by tedison           #+#    #+#             */
/*   Updated: 2021/04/21 11:02:07 by tedison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_putchar(char c);

int	is_valid(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == 0 || base[1] == 0)
		return (0);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(long long int nb, char *base, int *inc)
{
	unsigned long long int	nbr;
	unsigned int			size;

	size = 0;
	if (!is_valid(base))
		return ;
	while (base[size])
		size++;
	nbr = nb;
	if (nb < 0)
		nbr = -nbr;
	if (nbr < size)
		*inc += ft_putchar(base[nbr]);
	else
	{
		ft_putnbr_base(nbr / size, base, inc);
		ft_putnbr_base(nbr % size, base, inc);
	}
}
