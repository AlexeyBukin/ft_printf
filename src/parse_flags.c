/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmelina <lmelina@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 19:26:49 by lmelina           #+#    #+#             */
/*   Updated: 2019/12/21 15:34:24 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		is_in_args(int ch)
{
	if (ch == '\0')
		return (-1);
	if (ch == '.' || (ch >= '0' && ch <= '9'))
		return (1);
	if (ch == '-' || ch == '+' || ch == ' ' || ch == '#')
		return (1);
	if (ch == 'L' || ch == 'l' || ch == 'h')
		return (1);
	if (ch == 's' || ch == 'c' || ch == 'x' || ch == 'p' || ch == 'X')
		return (2);
	if (ch == 'o' || ch == 'u' || ch == '%' || ch == 'd')
		return (2);
	if (ch == 'i' || ch == 'f' || ch == 'F')
		return (2);
	return (0);
}

int		arg_len(char *string)
{
	int		c;
	int		i;

	i = 0;
	while ((c = is_in_args(string[i])) > 0)
	{
		if (c == 2)
			break ;
		i++;
	}
	if (c != 2)
		return (-1);
	return (i + 1);
}

int		parse_flags(char *args, int len, int *flags)
{
	int		dot_passed;
	int		i;

	if (args == NULL || flags == NULL)
		return (-1);
	if (len < 1)
		return (-1);
	i = -1;
	while (++i < FLAGS_LEN)
		flags[i] = 0;
	dot_passed = 0;
	i = 0;
	flags[FLAG] = args[len - 1];
	flags[PRECISION] = -1;
	while (i < len - 1)
	{
		if (args[i] == '.')
		{
			dot_passed = 1;
			flags[PRECISION] = 0;
		}
		if (args[i] == '-')
			flags[MINUS] = 1;
		else if (args[i] == '+')
			flags[PLUS] = 1;
		else if (args[i] == ' ')
			flags[SPACE] = 1;
		else if (args[i] == '#')
			flags[SHARP] = 1;
		else if (args[i] == '0' && dot_passed == 0)
			flags[ZERO] = 1;
		else if (args[i] > '0' && args[i] <= '9')
		{
			if (dot_passed == 0)
				flags[WIDTH] = ft_atoi(&(args[i]));
			else
				flags[PRECISION] = ft_atoi(&(args[i]));
			while (args[i] >= '0' && args[i] <= '9')
				i++;
			continue ;
		}
		else if (args[i] == 'l')
		{
			if (args[i + 1] == 'l')
			{
				flags[CAST] = CAST_LL;
				i = i + 2;
				continue ;
			}
			flags[CAST] = CAST_L;
		}
		else if (args[i] == 'h')
			if (args[i + 1] == 'h')
			{
				flags[CAST] = CAST_HH;
				i = i + 2;
			}
			else
				flags[CAST] = CAST_H;
		else if (args[i] == 'L')
			flags[CAST] = CAST_BIG_L;
		i++;
	}
	if (flags[PRECISION] == -1)
		flags[PRECISION] = 0;
	else if (flags[PRECISION] == 0)
		flags[PRECISION] = PREC_INTENDED_ZERO;

	if (flags[WIDTH] < 0)
		flags[WIDTH] = 0;
	if (flags[PRECISION] < -1)
		flags[PRECISION] = 0;

	return (0);
}
