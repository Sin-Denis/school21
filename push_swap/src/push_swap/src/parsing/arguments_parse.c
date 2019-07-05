#include "../../inc/push_swap.h"

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

static int		vector_has_duplicate(t_vector *v)
{
	vector_quick_sort(v);
	for (int i = 0; i + 1 < vector_length(v); ++i) {
		if (vector_get_elem(v, i) == vector_get_elem(v, i + 1))
			return (1);
	}
	return (0);
}

static void		arguments_parse_body(t_stack *s, t_vector *v, char **args, int *flag)
{
	int 		j;

	j = -1;
	while (args[++j] != NULL)
	{
		if (!is_integer_number(args[j]))
			--(*flag);
		vector_push_back(v, ft_atoi(args[j]));
		stack_push_front(s, ft_atoi(args[j]));
	}
}

static void		arr_str_destroy(char ***arr)
{
	int			i;

	i = -1;
	while ((*arr)[++i])
		free((*arr)[i]);
	free(*arr);
	*arr = NULL;
}

int				arguments_parse(t_stack *a, int argc, char **argv)
{
	int			i;
	int			flag;
	char 		**args;
	t_vector	*v;

	i = 0;
	flag = 0;
	v = vector_create(0);
	while (++i < argc && flag == 0)
	{
		args = ft_strsplit(argv[i], ' ');
		arguments_parse_body(a, v, args, &flag);
		arr_str_destroy(&args);
	}
	if (flag == -1 || vector_has_duplicate(v))
	{
		vector_destroy(&v);
		stack_clean(a);
		return (-1);
	}
	vector_destroy(&v);
	return (0);
}

