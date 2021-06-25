#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>
# include "libft.h"

typedef struct s_print
{
	va_list	args;
	int		width;
	int		precision;
	int		zero;
	int		dot;
	int		dash;
	int		lenght;
	int		sign;
	int		is_zero;
	int		precent;
	int		space;
}	t_print;

int		ft_printf(const char *format, ...);
t_print	*ft_init_flag(t_print *flag);
int		ft_edit_format(t_print *flag, const char *format, int i);
t_print	*ft_reset_flag(t_print *flag);
int		ft_edit_variable(t_print *flag, const char *format, int i);
void	ft_percentage(t_print *flag);
int		ft_edit_width(t_print *flag, const char *format, int i);
int		ft_edit_precision(t_print *flag, const char *format, int i);
int		ft_edit_star(t_print *flag, const char *format, int i);
int		ft_edit_dash(t_print *flag, const char *format, int i);
int		ft_edit_zero(t_print *flag, const char *format, int i);
void	ft_print_pointer(t_print *flag);
void	ft_print_hexa(t_print *flag, int c);
void	ft_print_char(t_print *flag);
void	ft_print_str(t_print *flag);
int		ft_edit_space(t_print *flag, int i);
void	ft_right_cs(t_print *flag, int len);
int		ft_update_len(char *s, t_print *flag, int len);
void	ft_write_point(t_print *flag);
void	ft_print_int(t_print *flag);
void	ft_write_zero(t_print *flag);
void	ft_right_zero(t_print *flag);
void	ft_update_flag(t_print *flag, int len);
void	ft_right_id(t_print *flag);
void	ft_left_id(t_print *flag);
int		ft_check_sign(t_print *flag, int j);
void	ft_write_zero_point(t_print *flag);
void	ft_print_unsigned_int(t_print *flag);
void	ft_write_null_add(t_print *flag);

#endif
