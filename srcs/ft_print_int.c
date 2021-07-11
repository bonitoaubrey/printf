#include "../includes/ft_printf.h"
#include "../libft/libft.h"

void	ft_print_int(t_print *flag)
{
	char	*num;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = va_arg(flag->args, int);
	if (!j)
	{
		flag->lenght += write(1, "0", 1);
		return ;
	}
	if (j < 0)
	{
		j *= -1;
		flag->lenght += write(1, "-", 1);
	}
	num = ft_itoa(j);
	if (!num)
		return ;
	len = ft_strlen(num);
	while (j && num[i])
		flag->lenght += write(1, &num[i++], 1);
	free (num);
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
		flag->lenght += write(1, "0", 1);
		return ;
	}
	num = ft_uitoa(j);
	if (!num)
		return ;
	len = ft_strlen(num);
	while (j && num[i])
		flag->lenght += write(1, &num[i++], 1);
	free(num);
}
