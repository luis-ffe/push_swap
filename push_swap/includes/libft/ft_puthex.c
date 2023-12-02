/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luis-ffe <luis-ffe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 09:13:39 by luis-ffe          #+#    #+#             */
/*   Updated: 2023/11/10 18:38:45 by luis-ffe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex_pf(unsigned int num, int fd, int j)
{
	int				x;
	unsigned int	n;

	x = 0;
	n = num;
	if (num == 0)
		return (write (fd, "0", 1));
	if (num < 16)
	{
		if (j == 1)
			write (fd, &"0123456789abcdef"[num], 1);
		else
			write (fd, &"0123456789ABCDEF"[num], 1);
	}
	else
	{
		ft_puthex_pf(num / 16, fd, j);
		ft_puthex_pf(num % 16, fd, j);
	}
	while (n)
	{
		n /= 16;
		x++;
	}
	return (x);
}
