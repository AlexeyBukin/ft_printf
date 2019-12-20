/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 16:20:27 by kcharla           #+#    #+#             */
/*   Updated: 2019/12/16 17:45:05 by lmelina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_str_low(char *s)
{
	size_t	i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		s[i] = ft_tolower(s[i]);
		i++;
	}
	return ;
}
