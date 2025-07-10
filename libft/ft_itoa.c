/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pnurmi <pnurmi@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 14:31:23 by pnurmi            #+#    #+#             */
/*   Updated: 2025/05/04 14:33:35 by pnurmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digit(int n);
static void	ft_calc(char *str, long *num, int index);

char	*ft_itoa(int n)
{
	int		i;
	int		sign;
	char	*result;
	long	nbr;

	sign = 0;
	nbr = n;
	if (n < 0)
	{
		sign = 1;
		nbr = -nbr;
	}
	result = malloc(ft_digit(n) + 1);
	if (!result)
		return (NULL);
	i = ft_digit(n) - 1;
	if (nbr == 0)
		result[0] = '0';
	while (nbr != 0)
		ft_calc(result, &nbr, i--);
	if (sign == 1 && n != 0)
		result[0] = '-';
	result[ft_digit(n)] = '\0';
	return (result);
}

static int	ft_digit(int n)
{
	int	potato;

	if (n == 0)
		return (1);
	potato = 0;
	if (n < 0)
		potato++;
	while (n != 0)
	{
		n = n / 10;
		potato++;
	}
	return (potato);
}

static void	ft_calc(char *str, long *num, int index)
{
	str[index] = ((*num % 10) + 48);
	*num = *num / 10;
}
