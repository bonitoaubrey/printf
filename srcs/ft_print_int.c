#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_update_flag(t_print *flag, int len)
{
	if (flag->sign)
		if (flag->width)
			flag->width -= 1;
	if (flag->precision > 0)
		flag->zero = 0;
	if (flag->width && flag->width >= flag->precision)
	{
		if (flag->precision > len)
			flag->precision -= len;
		else
			flag->precision = 0;
		if (!flag->is_zero)
			flag->width = flag->width - flag->precision - len;
	}
	else if (flag->precision > flag->width)
	{
		flag->width = 0;
		flag->precision -= len;
	}
}

void	ft_write_zero_point(t_print *flag)
{
	if (flag->precision < 0)
		flag->lenght += write(1, "0", 1);
	while (!flag->width && flag->precision-- > 0)
		flag->lenght += write(1, "0", 1);
}

void	ft_write_zero(t_print *flag)
{
	flag->is_zero = 1;
	if ((flag->width && flag->zero) || flag-> dot)
	{
		ft_right_zero(flag);
		return ;
	}
	while (!flag->dash && --flag->width > 0)
		flag->lenght += write(1, " ", 1);
	flag->lenght += write(1, "0", 1);
	while (flag->dash && --flag->width > 0)
		flag->lenght += write(1, " ", 1);
}

void	ft_print_int(t_print *flag)
{
	int		len;
	int		i;
	int		j;
	char	*num;

	i = 0;
	j = va_arg(flag->args, int);
	if (!j)
	{
		ft_write_zero(flag);
		return ;
	}
	if (j < 0)
		j = ft_check_sign(flag, j);
	num = ft_itoa(j);
	if (!num)
		return ;
	len = ft_strlen(num);
	ft_update_flag(flag, len);
	ft_right_id(flag);
	while (j && num[i])
		flag->lenght += write(1, &num[i++], 1);
	ft_left_id(flag);
	free(num);
}

void	ft_print_unsigned_int(t_print *flag)
{
	int				len;
	int				i;
	unsigned int	j;
	char			*num;

	i = 0;
	j = va_arg(flag->args, int);
	if (!j)
	{
		ft_write_zero(flag);
		return ;
	}
	num = ft_uitoa(j);
	if (!num)
		return ;
	len = ft_strlen(num);
	ft_update_flag(flag, len);
	ft_right_id(flag);
	while (j && num[i])
		flag->lenght += write(1, &num[i++], 1);
	ft_left_id(flag);
	free(num);
}
