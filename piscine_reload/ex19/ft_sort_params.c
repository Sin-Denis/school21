/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblue-da <jblue-da@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 18:08:58 by jblue-da          #+#    #+#             */
/*   Updated: 2018/11/20 19:05:46 by jblue-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_putchar(char c);

void		ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
}

int			ft_strcmp(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0' && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

void		choice_sort(char **a, int size)
{
	int		i;
	int		j;
	char	*tmp;

	i = 1;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (ft_strcmp(a[i], a[j]) > 0)
			{
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int			main(int argc, char **argv)
{
	int		i;

	i = 1;
	if (argc <= 1)
	{
		return (0);
	}
	choice_sort(argv, argc);
	while (i < argc)
	{
		ft_putstr(argv[i]);
		ft_putstr("\n");
		i++;
	}
	return (0);
}
