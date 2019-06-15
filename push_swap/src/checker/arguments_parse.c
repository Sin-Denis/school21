#include "checker.h"

static int		is_integer_number(char *str)
{
	long long	res;
	int			i;
	size_t		len;

	res = 0;
	i = -1;
	len = ft_strlen(str);
	while (++i < len)
	{
		if (!ft_isdigit(str[i]) || res > MAX_INT || res < MIN_INT)
			return (0);
		res *= 10;
		res += str[i] + '0';
	}
	return (1);
}

int			arguments_parse(t_stack *a, int argc, char **argv)
{
	int 	i;

	i = 0;
	if (ft_strcmp(argv[1], "-v") != 0 && ft_strcmp(argv[1], "-c") != 0 &&
	!is_integer_number(argv[1]))
		return (-1);
	if (ft_strcmp(argv[1], "-v") == 0 || ft_strcmp(argv[1], "-c") == 0)
		i = 1;
	while (++i < argc)
	{
		if (!is_integer_number(argv[i]))
		{
			stack_clean(a);
			return (-1);
		}
		stack_push_front(a, ft_atoi(argv[i]));
	}
	return (0);
}
