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

#endif
