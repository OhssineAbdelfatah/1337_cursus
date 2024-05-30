/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_02.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 10:29:37 by aohssine          #+#    #+#             */
/*   Updated: 2024/05/29 11:04:11 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	mini_check(char **argv, int i, int j)
{
	if (is_sign_doubled(argv[i][j], argv[i][j + 1]) || (ft_isdigit(argv[i][j])
			&& is_sign(argv[i][j + 1])))
		return (-1);
	if (is_sign(argv[i][j]) && (is_sign(argv[i][j + 1]) || is_space(argv[i][j
				+ 1])))
		return (-1);
	if (!ft_isdigit(argv[i][j]) && !is_space(argv[i][j])
		&& !is_sign(argv[i][j]))
		return (-1);
	if (is_sign(argv[i][j]) && argv[i][j + 1] == '\0')
		return (-1);
	return (0);
}

int	check_args(int len, char **argv)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	while (++i < len)
	{
		if (argv[i][0] == '\0')
			return (-1);
		j = -1;
		flag = 0;
		while (argv[i][++j])
		{
			if (mini_check(argv, i, j) == -1)
				return (-1);
			if (is_space(argv[i][j]))
				flag++;
		}
		if (flag == j)
			return (-1);
	}
	return (0);
}

t_node	*fill_args(char **argv)
{
	int		i;
	int		j;
	char	**arg;
	t_node	*head;

	head = NULL;
	i = 0;
	while (argv[++i])
	{
		arg = ft_split(argv[i], ' ');
		j = -1;
		while (arg[++j])
		{
			if (is_max(ft_atol(arg[j])))
				return (NULL);
			add_to_stack(creat_node((int)ft_atol(arg[j])), &head);
			free(arg[j]);
		}
		free(arg[j]);
		free(arg);
	}
	if (check_double(head) == -1)
		return (NULL);
	return (head);
}

static int	space_sign(const char *s, int *sign)
{
	int	i;

	i = 0;
	while (s[i] && (s[i] == 32 || (s[i] < 14 && s[i] > 8)))
		i++;
	if (s[i] && (s[i] == '-' || s[i] == '+'))
	{
		if (s[i] == '-')
			*sign *= (-1);
		i++;
	}
	return (i);
}

long	ft_atol(const char *str)
{
	int					i;
	int					sign;
	unsigned long long	result;
	unsigned long long	temp;

	result = 0;
	sign = 1;
	i = space_sign(str, &sign);
	while (str[i] <= '9' && str[i] >= '0')
	{
		temp = result;
		result = result * 10 + str[i] - 48;
		i++;
	}
	return (result * sign);
}
