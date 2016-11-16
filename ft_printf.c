/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpassafa <rpassafa@student.42.us>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:43:45 by rpassafa          #+#    #+#             */
/*   Updated: 2016/11/16 00:36:30 by rpassafa         ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h> //testing use

char *g_format = "sSpdDioOuUxXcC";

void (*g_gl[14])(va_list *ptr, s_flags **flag) =
{
	&pf_putstr, 	//0			s
	&pf_putstr, 	//1 		S
	&pf_p_handle,	//2 		p
	&pf_putnbr, 	//3			d
	&pf_putnbr, 	//4			D
	&pf_putnbr, 	//5			i
	&pf_o_handle, 	//6			o
	&pf_oup_handle, //7			O
	NULL, 			//8			u
	NULL, 			//9			U
	&pf_xlow_handle,//10		x
	&pf_x_handle,	//11		X
	&pf_putchar, 	//12		c
	&pf_putchar, 	//13		C
};

int findfunind(char c)
{
	int i;

	i = 0;
	while (g_format[i])
	{
		if(g_format[i] == c)
			return i;
		i++;
	}
	return -1;
}

int ft_printf(const char *format, ...)
{
	int findex;
	va_list args;
	s_flags *flag;
	flag = malloc(sizeof(s_flags));
	findex = 0;
	va_start(args,format);
	while (format[findex])
	{
		setflags(&flag);
		if (format[findex] == '%')
		{
			findex++;
			if (format[findex] == '#' || format[findex] == '0'
				|| format[findex] == '-' || format[findex] == '+' ||
				format[findex] == ' ')
				setsymb(&flag,&findex,format);
			if (format[findex] == '.')
				flag->precision = findprecision(format, &findex);
			findflags(&flag, &findex, format);
			g_gl[findfunind(format[findex])](&args,&flag);
			//flagformating(&flag); //flag handling
		}
		else
			ft_putchar(format[findex]);
		findex++;
	}
	va_end(args);
	return flag->mflag;
}
