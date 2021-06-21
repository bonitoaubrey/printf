#include "../includes/ft_printf.h"
#include "../libft/libft.h"

int	ft_edit_variable (t_print *flag, const char *format, int i)
{
	if (format[i] == '%')
		ft_percentage(flag);
	return (i);
}

int	ft_edit_format(t_print *flag, const char *format, int i)
{
	ft_edit_variable(flag, format, i);
	ft_reset_flag(flag);
	return (i);
}
