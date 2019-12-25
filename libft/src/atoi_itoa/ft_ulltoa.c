/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 16:45:50 by kcharla           #+#    #+#             */
/*   Updated: 2019/12/24 21:55:18 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_ulltoa(unsigned long long int n)
{
	uint8_t len;
	char	*res;

	res = NULL;
	len = 0;
	if (n == 0)
	{
		res = ft_strdup("0");
	}
	else
	{
		while (n / power_ten(len) / 10 != 0)
			len++;
		len++;
		res = (char*)malloc(sizeof(char) * (len + 1));
		if (res == NULL)
			return (NULL);
		res[len] = '\0';
		while (n != 0)
		{
			res[len - 1] = n % 10 + '0';
			n = n / 10;
			len--;
		}
	}
	return (res);
}
