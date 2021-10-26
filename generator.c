#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int				i;
	long long int	sign;
	long long int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == '\t' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\n' || str[i] == '\r' || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - 48;
		i++;
	}
	res = res * sign;
	return ((int)res);
}

int		is_doublon(int *tab, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
				if (tab[i] == tab[j])
					return (1);
				j++;
		}
		i++;
	}
	return (0);
}

int main(int ac, char **av)
{
	int	curr;
	int n;
	int i;
	int min;
	int max;
	int	*tab;

	curr = 0;
	i = 0;
	if (ac != 4)
	{
		printf("model : \"./a.out nb_of_digits_wanted nb_min nb_max\"\n");
		return (0);
	}
	n = ft_atoi(av[1]);
	min = ft_atoi(av[2]);
	max = ft_atoi(av[3]);
	tab = malloc(sizeof(int) * n);
	while (i < n)
	{
		tab[i] = 0;
		i++;
	}
	while (is_doublon(tab, n))
	{
		i = 0;
		while (i < n)
		{
			tab[i] = (rand() + getpid()) % (max - min + 1) + 1;
			i++;
		}
	}
	i = 0;
	while (i < n)
	{
		if (i < n - 1)
			printf("%d, ", tab[i]);
		else
			printf("%d\n", tab[i]);
		i++;
	}
}
