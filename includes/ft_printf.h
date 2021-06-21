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

#endif
