/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi_base_ref.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: mraasvel <mraasvel@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/08 14:48:47 by mraasvel      #+#    #+#                 */
/*   Updated: 2021/03/10 12:14:08 by mraasvel      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int	valid_basechar(char c)
{
	if (c == '+' || c == '-')
		return (0);
	if (ft_isspace(c))
		return (0);
	return (1);
}

int	check_base(char *base)
{
	int	i;
	int	ascii[255];

	i = 0;
	while (i < 255)
	{
		ascii[i] = 0;
		i++;
	}
	i = 0;
	while (base[i] != 0)
	{
		if (ascii[(int)base[i]] == 1 || valid_basechar(base[i]) == 0)
			return (0);
		ascii[(int)base[i]] = 1;
		i++;
	}
	return (i);
}

int	ft_isbase(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base_ref(char *str, char *base)
{
	int	num;
	int	radix;
	int	negative;

	radix = check_base(base);
	if (radix < 2)
		return (0);
	while (ft_isspace(*str))
		str++;
	negative = 1;
	if (*str == '-')
		negative = -1;
	if (*str == '+' || *str == '-')
		str++;
	num = 0;
	while (ft_isbase(*str, base) >= 0)
	{
		num = (num * radix) + ft_isbase(*str, base);
		str++;
	}
	return (num * negative);
}
