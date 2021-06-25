#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_print_char(t_print *flag)
{
	char	c;

	c = va_arg(flag->args, int);
	ft_update_flag(flag, 1);
	if (flag->width && !flag->dash)
		ft_right_cs(flag, 0);
	flag->lenght += write(1, &c, 1);
	if (flag->width && flag->dash)
	{
		while (flag->zero && flag->width-- > 0)
			flag->lenght += write(1, "0", 1);
		while (!flag->zero && flag->width-- > 0)
			flag->lenght += write(1, " ", 1);
	}
}

void	ft_percentage(t_print *flag)
{
	flag->lenght += write(1, "%", 1);
}

int	ft_edit_space(t_print *flag, int i)
{
	i++;
	flag->space = 1;
	return (i);
}
