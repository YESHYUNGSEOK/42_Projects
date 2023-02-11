/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyungnoh <hyungnoh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 16:29:16 by hyungnoh          #+#    #+#             */
/*   Updated: 2022/12/01 20:54:39 by hyungnoh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# define W_ERROR -1

int		print_c(va_list *ap);
int		print_s(va_list *ap);
int		print_p(va_list *ap);
int		print_d(va_list *ap);
int		print_i(va_list *ap);
int		print_u(va_list *ap);
int		print_x(va_list *ap);
int		print_bx(va_list *ap);
int		print_per(void);
void	ft_puthex(size_t n, int *cnt);
void	ft_putbighex(size_t n, int *cnt);
void	ft_putnbr(int n, int *cnt);
void	ft_int_min(int *cnt);
void	ft_putunsigned(size_t n, int *cnt);
int		ft_printf(const char *str, ...);

#endif