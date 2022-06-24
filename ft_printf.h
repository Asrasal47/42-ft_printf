/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arasal <arasal@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 00:13:18 by arasal            #+#    #+#             */
/*   Updated: 2022/05/08 13:18:20 by arasal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int		plus;
	int		space;
	int		minus;
	int		zero;
	int		hash;
	int		width;
	int		precision;
	char	*h;
	int		len;
	char	ch;
	char	*s;
}					t_flags;

int			ft_printf(const char *s, ...);
t_flags		ft_flags(const char **s);
int			ft_putchar_fd(char c);
int			ft_putchar(char c, t_flags f);
int			ft_putstr(const char *s, t_flags f);
int			ft_putnbr(int n, t_flags f);
char		*ft_setstr_norm(int nbr, char **s, t_flags *f);
char		*ft_setstr(t_flags f, int nbr, int len, long long n);
long long	ft_putnbr_norm(int nbr, int *len, t_flags *f);
int			ft_putnbr_unsigned(unsigned int n, t_flags f);
char		*ft_setstr_u(char *str, t_flags f, unsigned long long n);
int			ft_putnbr_hex(unsigned int nbr, char c, t_flags f);
int			ft_putnbr_hex_fd(unsigned int nbr, char c);
int			ft_putnbr_hex_counter(unsigned long nbr);
int			ft_putadd(unsigned long add, t_flags f);
int			ft_putadd_fd(unsigned long add);
char		*ft_itoa(long long n2, t_flags f);
void		ft_itoa_f(int sign, char *str, long long n, t_flags f);
int			ft_strlen(const char *s);
char		*ft_calloc(int count, char c);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strchr(const char *s, int c);
int			ft_atoi(const char *str);
int			ft_putstr_fd(char *s);

#endif