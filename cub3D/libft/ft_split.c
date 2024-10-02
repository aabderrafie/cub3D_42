/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 00:48:54 by aaskal            #+#    #+#             */
/*   Updated: 2023/12/22 23:50:38 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		while (s[i] != c && s[i])
			i++;
		count++;
		while (s[i] == c && s[i])
			i++;
	}
	return (count);
}

static char	**free_strs(char **strs, size_t j)
{
	while (j > 0)
	{
		free(strs[j - 1]);
		j--;
	}
	free(strs);
	return (NULL);
}

static char	**extract_substrings(char const *s, char c, char **strs)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		k = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (i > k)
		{
			strs[j] = ft_substr(s, k, i - k);
			if (!strs[j])
				return (free_strs(strs, j));
			j++;
		}
	}
	strs[j] = NULL;
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	size_t	len;

	if (!s)
		return (NULL);
	len = count_words(s, c);
	strs = (char **)malloc((len + 1) * sizeof(char *));
	if (strs == NULL)
		return (NULL);
	return (extract_substrings(s, c, strs));
}

// int	main(void)
// {
// 	char **strs;
// 	int i;

// 	i = 0;

// 	if (ft_split(NULL, '\0') == NULL)
// 		printf("NULL\n");
// 	while (strs[i])
// 	{
// 		printf("%s\n", strs[i])
// 		i++;
// 	}
// 	return (0);
// }