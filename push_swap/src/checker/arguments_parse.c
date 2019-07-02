#include "checker.h"

static int		is_integer_number(char *str)
{
	long long	res;
	int			i;
	int 		sign;
	size_t		len;

	res = 0;
	sign = 0;
	i =  -1;
	len = ft_strlen(str);
	if (str[0] == '-')
	{
		++i;
		sign = -1;
	}
	while (++i < len)
	{
		if (!ft_isdigit(str[i]) ||
			(sign == -1 && res < MIN_INT) || (sign == 0 && res > MAX_INT))
			return (0);
		res *= 10;
		res += str[i] + '0';
	}
	return (1);
}

int				vector_has_duplicate(t_vector *v)
{
	vector_quick_sort(v);
	for (int i = 0; i + 1 < vector_length(v); ++i) {
		if (vector_get_elem(v, i) == vector_get_elem(v, i + 1))
			return (1);
	}
	return (0);
}			

int				arguments_parse(t_stack *a, int argc, char **argv)
{
	int			i;
	int			flag;
	t_vector	*v;

	i = (ft_strcmp(argv[1], "-v") == 0 || ft_strcmp(argv[1], "-c") == 0) ? 1 : 0;
	flag = 0;
	v = vector_create(0);
	if (ft_strcmp(argv[1], "-v") != 0 && ft_strcmp(argv[1], "-c") != 0 &&
	!is_integer_number(argv[1]))
		return (-1);
	while (++i < argc && flag == 0)
	{
		if (!is_integer_number(argv[i]))
			--flag;
		vector_push_back(v, ft_atoi(argv[i]));
		stack_push_front(a, ft_atoi(argv[i]));
	}
	if (flag == -1 || vector_has_duplicate(v))
	{
		vector_destroy(&v);
		stack_clean(a);
		return (-1);
	}
	return (0);
}
