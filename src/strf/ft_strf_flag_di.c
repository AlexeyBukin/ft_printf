/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strf_flag_di.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 08:08:02 by kcharla           #+#    #+#             */
/*   Updated: 2020/08/08 14:57:06 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strf.h"

char		*ft_strf_flag_di(va_list arg, t_strflags *flags)
{
	char			*res;
	long long int	d;

	if (flags == NULL || ft_strf_cast_flag_lli(&d, flags, arg))
		return (NULL);
	flags->num_sign = (char)d;
	res = (flags->precision == 0 && d == 0)
			? ft_strdup("") : ft_ulltoa(ft_absl(d));
	ft_strf_adjust_di(flags);
	res = ft_strf_format_prec(res, flags);
	res = ft_strf_format_zero(res, flags);
	if (d < 0)
		res = ft_strjoin_free(ft_strdup("-"), res);
	if (flags->plus == 1 && d >= 0)
		res = ft_strjoin_free(ft_strdup("+"), res);
	if (flags->space == 1 && flags->plus == 0 && d >= 0)
		res = ft_strjoin_free(ft_strdup(" "), res);
	res = ft_strf_format_width(res, flags);
	return (res);
}
