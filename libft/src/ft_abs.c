/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 18:49:38 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/11 05:05:25 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_abs(int a)
{
	if (a < 0)
		return (a * (-1));
	return (a);
}

long long int	ft_absl(long long int a)
{
	if (a < 0)
		return (a * (-1));
	return (a);
}

t_uintmax	ft_abs_max(t_intmax a)
{
	t_uintmax	b;

	b = a;
	return (b);
}