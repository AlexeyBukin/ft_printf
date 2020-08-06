/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcharla <kcharla@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/23 15:00:26 by lmelina           #+#    #+#             */
/*   Updated: 2020/08/06 15:10:50 by kcharla          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRF_H
# define FT_STRF_H

# include <math.h>
# include <float.h>
# include <stdarg.h>
# include "libft.h"
# include "ldouble.h"

//typedef enum	e_format_cast
//{
//	CAST_NO,
//	CAST_HH,
//	CAST_H,
//	CAST_L,
//	CAST_LL,
//	CAST_BIG_L
//}				t_format_cast;

//# define CAST_NO    0
//# define CAST_HH    1
//# define CAST_H     2
//# define CAST_L     3
//# define CAST_LL    4
//# define CAST_BIG_L 5

# define F_N0_SPECIAL   1
# define F_NAN          2
# define F_INF          3
# define F_ROUND_NO     4
# define F_ROUND_YES    5

# define NULL_IN_THE_BEGINNING 1
# define NULL_IN_THE_END       2

# define PREC_INTENDED_ZERO -1

# define PRECISION  0
# define PLUS       1
# define MINUS      2
# define ZERO       3
# define SPACE      4
# define WIDTH      5
# define SHARP      6
# define CAST       7
# define C_GOT_NULL 8
# define FLAG       9
# define SPECIAL    10
# define FLAGS_LEN  11

# define LEN 0
# define IS_X_BIG 1

typedef struct	s_strflags
{
	char		type;
	char		plus;
	char		minus;
	char		zero;
	char		space;
	char		sharp;
	int			special;
	int			precision;
	char		dot;
	int			width;
	char		num_zero;
}				t_strflags;


#define FT_PRECISION_DEFAULT -1

char			*ft_strf(const char *restrict format, ...);

char			*ft_strf_flag_s(va_list arg, t_strflags *flags);
int				ft_strf_parse(char *args, t_strflags *flags, size_t *parsed_len);

/*
** resolving
*/

int				ft_strf_resolve(char **source, size_t *pos, t_strflags *flags, va_list arg);
int				ft_strf_resolve_ins(char **source, size_t *pos, size_t parsed_len, char *insertion);
int				ft_strf_resolve_text(char **insertion, t_strflags *flags, va_list arg);

/*
** formatting
*/

int				is_flag_num(char type);


char			*ft_strf_format(char *string, t_strflags *flags);
char			*ft_strf_format_prec(char *string, t_strflags *flags);
char			*ft_strf_format_width(char *string, t_strflags *flags);
char			*ft_strf_format_zero(char *string, t_strflags *flags);

/*
** flag adjustments
*/

void			ft_strf_adjust(t_strflags *flags);

void			ft_strf_adjust_di(t_strflags *flags);
void			ft_strf_adjust_o(t_strflags *flags);
void			ft_strf_adjust_u(t_strflags *flags);
void			ft_strf_adjust_x(t_strflags *flags);

void			ft_strf_adjust_p(t_strflags *flags);
void			ft_strf_adjust_f(t_strflags *flags);
void			ft_strf_adjust_s(t_strflags *flags);
void			ft_strf_adjust_c(t_strflags *flags);
void			ft_strf_adjust_perc(t_strflags *flags);









char			*insert_from_to(char *inp, char *ins, size_t from, size_t to);
//t_stg			ft_resolve_arg(char *string, va_list arg, int *flags);
char			*ft_insert_d(va_list arg, int *flags);
char			*ft_insert_o(va_list arg, int *flags);
char			*ft_insert_x(va_list arg, int *flags, int is_x_big);
char			*ft_insert_u(va_list arg, int *flags);
char			*ft_insert_p(va_list arg, int *flags);
char			*ft_insert_s(va_list arg, int *flags);
char			*ft_insert_percentage(int *flags);
char			*ft_insert_c(va_list arg, int *flags);

int				parse_flags(char *args, int len, int *flags);
int				arg_len(char *string);

/*
** flag 'f'
*/

char			*ft_float(va_list arg, int *flags);
char			*bad_way(int *flags, long double num);

char			*ft_before_dot(int *flags, long double num);
char			*ft_after_dot(long double num);

char			*f_after_dot(long double num);
char			*f_after_dot_prec(int *flags, long double num);

char			*f_get_special(int *flags);
int				f_is_special(long double num);

char			*width_format(int *flags, char *str, char sign);


#endif