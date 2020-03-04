
#include "libft.h"

/*
** we return anything except NULL in case of success
** a_r is address of res
*/

int		*cycle_in_atoi_backsp(const char *str, int *a_r, int *n, int *a_i)
{
	while (str[*a_i] >= '0' && str[*a_i] <= '9')
	{
		if (*a_r > INT_MAX / 10 || (*a_r == INT_MAX / 10 && str[*a_i] > '7'))
		{
			*n = -1;
			return (NULL);
		}
		else
			*a_r = *a_r * 10 + (str[*a_i] - '0');
		(*a_i)++;
	}
	return (a_r);
}

/*
** we return anything except NULL in case of success
*/

int		str_end_in_atoi_backsp(const char *str_i, int *n)
{
	int kk;

	if (str_i == '\0')
	{
		*n = 0;
		return (-1);
	}
	kk = 0;
	while (str_i[kk])
	{
		if (str_i[kk] == ' ')
			break ;
		kk++;
	}
	return (kk);
}

/*
** if int parsed then we put to p_numb what was parsed
** and return pointer to next char;
** if int was overflowed then return NULL;
*/

char	*ft_atoi_backsp(const char *str, int *p_numb, int *n)
{
	int	i;
	int	res;
	int	sign;
	int	kk;

	res = 0;
	sign = 1;
	i = ft_cut_backspaces(str);
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (ft_strstr(str, "2147483648") && sign == -1)
	{
		*p_numb = -2147483648;
		*n = 1;
		return ((char *)str + i + 10);
	}
	if (!(cycle_in_atoi_backsp(str, &res, n, &i)))
		return (NULL);
	*p_numb = sign * res;
	if ((kk = str_end_in_atoi_backsp(str + i, n)) == -1)
		return (NULL);
	*n = 1;
	return ((char *)str + i + kk);
}
