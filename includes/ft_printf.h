/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadouble <yadouble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 20:38:10 by yadouble          #+#    #+#             */
/*   Updated: 2018/08/14 17:21:30 by yadouble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define MIN_BASE_16 "0123456789abcdef"
# define MAJ_BASE_16 "0123456789ABCDEF"
# define BASE_8 "01234567"
# define NULLSTR "(null)"
# define TYPE "sSpPdDioOuUxXcC"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <locale.h>
# include <limits.h>
# include <libft.h>

typedef struct		s_check
{
	va_list			arg;
	int				flags;
	int				conv;
	char			buff[BUFF_SIZE + 1];
	char			type;
	int				width;
	int				prec;
	int				precwidth;
	int				i;
	int				bix;
	int				len;
	long long int	nb;
	uintmax_t		unb;
	wchar_t			c;
	int				a;
	int				save_bix;
	wchar_t			*strl;
	char			*str;
	int				total;
}					t_check;

typedef struct		s_var
{
	t_check			check;
}					t_var;

int					ft_printf(const char *format, ...);
int					ft_parsing_center(const char *fmt, t_var *var);
int					ft_parsing_control(t_var *var, const char *fmt);
void				ft_initvar(t_var *var);
void				ft_parse_flags(const char *fmt, t_var *var);
void				ft_parse_width(const char *fmt, t_var *var);
void				ft_parse_precision(const char *fmt, t_var *var);
void				ft_parse_conv(const char *fmt, t_var *var);
void				ft_parse_type(const char *fmt, t_var *var);
void				ft_buffer(t_var *var, char c);
void				ft_buffer_large_char(t_var *var, wchar_t c);
void				ft_process(t_var *var);
void				ft_process_2(t_var *var);
void				ft_conv_dec(t_var *var);
void				ft_conv_type_hex(t_var *var);
void				ft_conv_type_uns(t_var *var);
void				ft_conv_type_oct(t_var *var);
int					ft_nb_is_neg(t_var *var);
void				ft_process_int(t_var *var);
void				ft_process_hexadecimal(t_var *var);
void				ft_process_unsigned(t_var *var);
void				ft_process_octal(t_var *var);
void				ft_process_large_char(t_var *var);
void				ft_process_wstrings(t_var *var);
void				ft_process_noprec_wstrings(t_var *var, int i);
void				ft_process_strings(t_var *var);
int					ft_surrogates(t_var *var);
int					ft_check_surrogates(t_var *var);
void				ft_print_one_byte_char(t_var *var);
void				ft_print_two_bytes_char(t_var *var);
void				ft_print_three_bytes_char(t_var *var);
void				ft_print_four_bytes_char(t_var *var);
void				ft_len(t_var *var);
void				ft_hxlen(t_var *var);
void				ft_unsigned_len(t_var *var);
void				ft_octlen(t_var *var);
int					ft_numlen(t_var *var);
void				ft_charlen(t_var *var);
int					ft_get_wcharlen(wchar_t c);
void				ft_stringlen(t_var *var);
void				ft_wstringlen(t_var *var);
void				ft_process_flags(t_var *var);
void				ft_process_flags_2(t_var *var, int i);
void				ft_process_prec(t_var *var);
void				ft_process_width(t_var *var);
void				ft_process_width_2(t_var *var, int i);
void				ft_process_minus(t_var *var, int neg);
int					ft_width_type_option(t_var *var);
int					ft_width_type_option_2(t_var *var, int i);
int					ft_width_type_option_3(t_var *var, int i);
int					ft_width_type_option_4(t_var *var, int i);
void				ft_prec_type_option(t_var *var);
int					ft_flags_type_option(t_var *var);
int					ft_flags_type_option_2(t_var *var, int i);
int					ft_minus_type_option(t_var *var, int neg);
#endif
