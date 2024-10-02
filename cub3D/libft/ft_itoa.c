/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 16:23:27 by aaskal            #+#    #+#             */
/*   Updated: 2023/12/21 15:23:08 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_numlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

void	fill_str(char *str, int n, int len)
{
	while (len > 0)
	{
		str[len - 1] = (n % 10) + '0';
		n /= 10;
		len--;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	int		sign;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_numlen(n);
	sign = 1;
	if (n < 0)
	{
		sign = -1;
		n *= -1;
	}
	str = (char *)malloc((len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	fill_str(str, n, len);
	if (sign == -1)
		str[0] = '-';
	return (str);
}
// int main()
// {
//     printf("%s \n", ft_itoa(2147483647));
//     printf("%s \n", ft_itoa(-2147483648));
//     return (0);
// }