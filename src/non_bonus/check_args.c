#include <string.h> // rm
#include <stdlib.h> // rm
#include "tester.h"

static const char	*get_id(int i)
{
	static const char	*ids[] = {
		"ft_strlen",
		"ft_strcpy",
		"ft_strcmp",
		"ft_write",
		"ft_read",
		"ft_strdup"
	};

	return (ids[i]);
}

static void	set_output(char *str, t_data *data)
{
	int	num;

	// import ft_atoi
	num = atoi(str);
	if (num == 0)
		data->output = ft_version;
	else if (num == 1)
		data->output = std_version;
	else
		data->output = both;
}

static t_bool	set_flags(char *str, t_data *data)
{
	int		i;
	t_bool	ret;

	i = 0;
	ret = false;
	while (i < FUNCTION_COUNT)
	{
		// Import libft strcmp
		if (strcmp(str, get_id(i)) == 0)
		{
			data->flags[i] = true;
			ret = true;
		}
		i++;
	}
	return (ret);
}

t_bool set_all_to_true(t_data *data)
{
	int	i;

	i = 0;
	while (i < FUNCTION_COUNT)
	{
		data->flags[i] = true;
		i++;
	}
	return (true);
}

t_bool	check_args(int argc, char *argv[], t_data *data)
{
	if (argc > 3)
		return (false);
	else if (argc == 3)
		set_output(argv[2], data);
	// replace strcmp
	if (argc == 1 || strcmp(argv[1], "all") == 0)
		return (set_all_to_true(data));
	if (argc == 2 && (argv[1][0] == '0' || argv[1][0] == '1'))
	{
		set_output(argv[1], data);
		return (set_all_to_true(data));
	}
	return (set_flags(argv[1], data));
}
