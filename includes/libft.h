/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 11:08:07 by erli              #+#    #+#             */
/*   Updated: 2018/11/29 13:00:20 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <string.h>

# define LEGAL_MOD "jzlhL"
# define LEGAL_CONV "diouxXcspf%eg"

typedef	struct	s_format
{
	unsigned char	pound;
	unsigned char	plus;
	unsigned char	minus;
	unsigned char	zero;
	unsigned char	space;
	unsigned char	pointer;
	int				m_width;
	int				precision;
	char			*data_format_modifier;
	char			conversion;
}				t_format;

typedef	struct	s_liststr
{
	char				*content;
	int					len;
	struct s_liststr	*next;
	struct s_liststr	*prev;
}				t_liststr;

typedef	int		(*t_converter)(t_format *, va_list, t_liststr **);

typedef struct	s_conv
{
	char		symbol;
	t_converter converter;
}				t_conv;

int				char_in_str(char c, char *str);
void			*ft_memalloc(size_t n, int c);
void			*ft_memalloc_c(size_t n, int c);
char			*ft_strdup(const char *src);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strjoinfree(char **s1, char **s2, int n);
size_t			ft_strlen(const char *s);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strsub(char *str, unsigned int begin, size_t len);
t_liststr		*lststr_create(char **cont, int len);
int				lststr_addback(t_liststr **list, char **cont, int len);
int				lststr_dellall(t_liststr **list);
int				lststr_len(t_liststr *list);
int				lststr_unload(t_liststr **list);

int				ft_printf(const char *format_str, ...);
int				write_free(int fd, char **str, size_t n);
char			*ft_strsub_i_j(char *str, size_t begin, size_t end);
int				ft_conv_d(t_format *format, va_list ap, t_liststr **list);
int				ft_conv_d_ptr(t_format *format, va_list ap, t_liststr **list);
int				ft_conv_d_ptrd(t_format *format, va_list ap, t_liststr **list);
int				ft_conv_d_ptrdh(t_format *format, va_list ap, t_liststr **list);
int				ft_conv_d_ptrdhh(t_format *format, va_list ap, t_liststr **list);
int				ft_conv_d_ptrdl(t_format *format, va_list ap, t_liststr **list);
int				ft_conv_d_ptrdll(t_format *format, va_list ap, t_liststr **list);
int				ft_conv_o_ptroll(t_format *format, va_list ap, t_liststr **list);
int				ft_conv_o_ptrol(t_format *format, va_list ap, t_liststr **list);
int				ft_conv_o_ptrohh(t_format *format, va_list ap, t_liststr **list);
int				ft_conv_o_ptroh(t_format *format, va_list ap, t_liststr **list);
int				ft_conv_o_ptro(t_format *format, va_list ap, t_liststr **list);
int				ft_conv_o_ptr(t_format *format, va_list ap, t_liststr **list);
int				ft_conv_f_ptr(t_format *format, va_list ap, t_liststr **list);
int				ft_conv_f_ptrfl(t_format *format, va_list ap, t_liststr **list);
int				ft_conv_f_ptrfbigl(t_format *format, va_list ap, t_liststr **list);
int				ft_conv_e_ptr(t_format *format, va_list ap, t_liststr **list);
int				ft_conv_e_ptrel(t_format *format, va_list ap, t_liststr **list);
int				ft_conv_e_ptrebigl(t_format *format, va_list ap, t_liststr **list);
int				ft_conv_g_ptr(t_format *format, va_list ap, t_liststr **list);
int				ft_conv_g_ptrgl(t_format *format, va_list ap, t_liststr **list);
int				ft_conv_g_ptrgbigl(t_format *format, va_list ap, t_liststr **list);
int				ft_conv_c_ptrc(t_format *format, va_list ap, t_liststr **list);
int				ft_conv_s_ptrs(t_format *format, va_list ap, t_liststr **list);
int				ft_conv_p_ptrp(t_format *format, va_list ap, t_liststr **list);
int				ft_conv_d_mat(t_format *format, va_list ap, t_liststr **list);
int				ft_conv_d_matd(t_format *format, va_list ap, t_liststr **list);
int				ft_conv_d_matdh(t_format *format, va_list ap, t_liststr **list);
int				ft_conv_d_matdhh(t_format *format, va_list ap, t_liststr **list);
int				ft_conv_d_matdl(t_format *format, va_list ap, t_liststr **list);
int				ft_conv_d_matdll(t_format *format, va_list ap, t_liststr **list);
int				ft_conv_o_mat(t_format *format, va_list ap, t_liststr **list);
int				ft_conv_o_mato(t_format *format, va_list ap, t_liststr **list);
int				ft_conv_o_matoh(t_format *format, va_list ap, t_liststr **list);
int				ft_conv_o_matohh(t_format *format, va_list ap, t_liststr **list);
int				ft_conv_o_matol(t_format *format, va_list ap, t_liststr **list);
int				ft_conv_o_matoll(t_format *format, va_list ap, t_liststr **list);
int				ft_conv_f_mat(t_format *format, va_list ap, t_liststr **list);
int				ft_conv_f_matfl(t_format *format, va_list ap, t_liststr **list);
int				ft_conv_f_matfbigl(t_format *format, va_list ap, t_liststr **list);
int				ft_conv_c_matc(t_format *format, va_list ap, t_liststr **list);
int				ft_conv_s_mats(t_format *format, va_list ap, t_liststr **list);
int				ft_conv_p_matp(t_format *format, va_list ap, t_liststr **list);
int				ft_conv_o(t_format *format, va_list ap, t_liststr **list);
int				ft_conv_u(t_format *format, va_list ap, t_liststr **list);
int				ft_conv_x(t_format *format, va_list ap, t_liststr **list);
int				ft_conv_big_x(t_format *format, va_list ap, t_liststr **list);
int				ft_conv_c(t_format *format, va_list ap, t_liststr **list);
int				ft_conv_s(t_format *format, va_list ap, t_liststr **list);
int				ft_conv_p(t_format *format, va_list ap, t_liststr **list);
int				ft_conv_f(t_format *format, va_list ap, t_liststr **list);
int				ft_conv_e(t_format *format, va_list ap, t_liststr **list);
int				ft_conv_big_e(t_format *format, va_list ap, t_liststr **list);
int				ft_conv_g(t_format *format, va_list ap, t_liststr **list);
int				ft_conv_percent(t_format *format, va_list ap, t_liststr **list);
int				ft_conv_not(t_format *format, va_list ap, t_liststr **list);
void			ft_round_up(char **str, int rest, char c, int i);
void			ft_round_up_slide(char **str);
int				ft_loophole(t_format *format, t_liststr **list, ...);
int				manage_format(const char *format_str, t_format **format,
					int *i, va_list ap);
int				init_format(t_format **format);
int				copy_format(t_format **format, t_format *source);
void			free_format(t_format *format);
int				get_converter(t_format *format, t_converter *fun);

#endif
