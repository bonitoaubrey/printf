#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_right_id(t_print *flag)
{
	if (flag->sign)
	{
		if (flag->zero || flag->dash || (!flag->width && !flag->precision))
		{
			flag->lenght += write(1, "-", 1);
			flag->sign = 0;
		}
	}
    if (!flag->dash)
    {
        while (!flag->zero && --flag->width > -1)
            flag->lenght += write(1, " ", 1);
		while (flag->zero && --flag->width > -1)
			flag->lenght += write(1, "0", 1);
		if (flag->sign)
			flag->lenght += write (1, "-", 1);
    }
	while (--flag->precision > -1)
		flag->lenght += write(1, "0", 1);
}

void	ft_left_id(t_print *flag)
{
	if (flag->dash)
	{
		while (--flag->width > -1)
			flag->lenght += write(1, " ", 1);
	}
}

int	ft_check_sign(t_print *flag, int j)
{
	flag->sign = 1;
	flag->space = 0;
	return (j * -1);
}

void	ft_right_zero(t_print *flag)
{
	if (flag->width && (flag->dot || flag->zero))
	{
		if (!flag->precision)
		{
			while (flag->zero && flag ->width-- > 0)
				flag->lenght += write(1, "0", 1);
			while (!flag->zero && flag->width-- > 0)
				flag->lenght += write(1, " ", 1);
		}
		else
		{
			flag->width -= flag->precision;
			while (flag->dash && flag ->precision-- > 0)
				flag->lenght += write(1, "0", 1);
			while (flag->width-- > 0)
				flag->lenght += write(1, " ", 1);
			while (!flag->dash && flag->precision-- > 0)
				flag-> lenght += write(1, "0", 1);
		}
	}
	else if (flag->dot)
		ft_write_zero_point(flag);
}