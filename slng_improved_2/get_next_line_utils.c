#include "so_long.h"

size_t	ft_strlen(char	*s)
{
	size_t	i;

	i = 0;
	while (s != 0 && s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup_itoa(const char *str)
{
	char	*dup;
	int		i;

	i = 0;

	dup = (char *)malloc(sizeof(char) *  ft_strlen_v(str) + 1);
	if (dup == NULL)
		return (NULL);
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

int	count_digits(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		len = 1;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*handle_zero(int n)
{
	char	*str;

	str = (char *)malloc(2 * sizeof(char));
	str[0] = n + '0';
	str[1] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	long	len;

	if (n == 0)
		return (handle_zero(0));
	if (n == -2147483648)
		return (ft_strdup_itoa("-2147483648"));
	len = count_digits(n);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (n > 0)
	{
		str[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
