/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassafa <rpassafa@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 15:29:27 by rpassafa          #+#    #+#             */
/*   Updated: 2016/11/16 05:14:29 by rpassafa         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "./libft/libft.h"

typedef	struct s_flags
{
	int z;// biggest to smallest
	int j;
	int	ll;
	int l;
	int h;
	int hh;
	int hash;
	int	zflag;
	int	mflag;
	int sign;
	int space;
	int precision;
	int isnegative;
}				s_flags;

extern char *g_format;
extern void (*g_gl[14])(va_list *ptr, s_flags **flag);
//pf wrappers
void 	pf_putstr(va_list *ptr, s_flags **flag);
void 	pf_putnbr(va_list *args, s_flags **flag);
void 	pf_putchar(va_list *args, s_flags **flag);
void 	pf_x_handle(va_list *args, s_flags **flag);
void 	pf_xlow_handle(va_list *args, s_flags **flag);
void 	pf_o_handle(va_list *args, s_flags **flag);
void 	pf_oup_handle(va_list *args, s_flags **flag);
void 	pf_p_handle(va_list *args, s_flags **flag);
void	setflags(s_flags **flag);
void	setsymb(s_flags **flag, int *findex, const char *format);
void	findflags(s_flags **flag, int *findex, const char *format);
//extra functions
int findsize(int value, int base);
char *betterjoin(char *first, char *second);
//handle
uintmax_t		ft_pow(uintmax_t nb, int pow);
char *ft_itoa_base(int value, int base);
char *ft_itoa_baselow(int value, int base);
//flag handlers
int checkzeroflag(s_flags **flag);
int findprecision(const char *format, int *findex);
//handle options
int findprecision(const char *format, int *findex);
char *flagformating(char *str, s_flags **flag);
void isnegative(s_flags **flag, int data);
//printf
int ft_printf(const char *format, ...);
#endif
