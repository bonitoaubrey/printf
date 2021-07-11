#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft.h"

typedef struct s_print
{
	va_list	args;
	int		lenght;
}	t_print;

int		ft_printf(const char *format, ...);
int		ft_format(t_print *flag, const char *format, int i);
void	ft_print_char(t_print *flat);
void	ft_print_hexa(t_print *flag, int c);
void	ft_print_unsigned_int(t_print *flag);
void	ft_print_int(t_print *flag);
void	ft_print_pointer(t_print *flag);
void	ft_print_str(t_print *flag);
void	ft_precentage(t_print *flag);

#endif
