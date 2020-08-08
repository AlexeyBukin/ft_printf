/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 14:57:18 by lmelina           #+#    #+#             */
/*   Updated: 2020/08/07 08:28:56 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "ft_strf.h"

int			is_flag_num(char type)
{
	if (ft_strchr("diouxX", type) != NULL)
		return (1);
	return (0);
}

int			ft_strf_is_in_args(int ch)
{
	if (ch == '\0')
		return (-1);
	if (ft_strchr(".1234567890-+ #Llh", ch) != NULL)
		return (1);
	if (ft_strchr("scp%diouxXfF", ch) != NULL)
		return (2);
	return (0);
}

char		*ft_strf(const char *restrict format, ...)
{
	t_strflags		sflags;
	va_list			arg;
	char			*res;
	size_t			i;

	res = ft_strdup((char *)format);
	va_start(arg, format);
	i = 0;
	while ((res)[i] != '\0')
	{
		if (res[i] == '%')
		{
			if (ft_strf_resolve(&res, &i, &sflags, arg))
			{
				free(res);
				return (NULL);
			}
		}
		i++;
	}
	return (res);
}
