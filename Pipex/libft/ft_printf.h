/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junssong <junssong@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 10:29:02 by junssong          #+#    #+#             */
/*   Updated: 2023/03/29 13:38:22 by junssong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int	ft_putnbr(int n);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_puthex_small(unsigned int num);
int	ft_puthex_large(unsigned int num);
int	ft_printf(const char *str, ...);
int	ft_putnbr_unsigned(unsigned int n);
int	ft_putpoint(void *ptr);

#endif
