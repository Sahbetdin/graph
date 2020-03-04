/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btrifle <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 21:48:04 by btrifle           #+#    #+#             */
/*   Updated: 2019/09/26 21:49:04 by btrifle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_factorial(int nb)
{
	if (nb < 0 || nb > 12)
		return (0);
	else if (nb == 1 || nb == 0)
		return (1);
	else
		return (nb * ft_factorial(nb - 1));
}