#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

long int	ft_atoi(const char *str)
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
	return ((long int)res);
}

int		is_doublon(long int *tab, long int size, long int n)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (tab[i] == n)
			return (1);
		i++;
	}
	return (0);
}

int main(int ac, char **av)
{
	long int	curr;
	long int n;
	long int i;
	long int min;
	long int max;
	long int	*tab;

	curr = 0;
	i = 0;
	srand((long int) time(0) + getpid());
	if (ac != 4)
	{
		printf("Model : \"./a.out nb_of_digits_wanted nb_min nb_max\"\n");
		return (0);
	}
	n = ft_atoi(av[1]);
	min = ft_atoi(av[2]);
	max = ft_atoi(av[3]);
	tab = malloc(sizeof(long int) * n);
	if (((max) - (min)) < n - 1)
	{
		printf("digits wanted : %ld, gap : %ld (max - min + 1). The number of digits wanted must be bigger than (nb_max - nb_min).\n", n, ((max) - (min) + 1));
		return (0);
	}
	while (i < n)
	{
		tab[i] = 0;
		i++;
	}
	i = 0;
	while (i < n)
	{
		curr = rand() % (max + 1 - min) + min;
		srand(rand());
		while (is_doublon(tab, i, curr))
		{
			curr = rand() % (max + 1 - min) + min;
			srand(rand());
		}
		tab[i] = curr;
		i++;
	}
	i = 0;
	while (i < n)
	{
		if (i < n - 1)
			printf("%ld ", tab[i]);
		else
			printf("%ld\n", tab[i]);
		i++;
	}
}
