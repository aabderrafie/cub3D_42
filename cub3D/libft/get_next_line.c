/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:25:27 by aaskal            #+#    #+#             */
/*   Updated: 2024/09/14 09:58:09 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_char(t_list *list)
{
	int		len;
	char	*str;

	len = 0;
	if (!list)
		return (0);
	while (list)
	{
		str = list->str;
		while (*str)
		{
			if (*str == '\n')
			{
				len++;
				return (len);
			}
			str++;
			len++;
		}
		list = list->next;
	}
	return (len);
}

t_list	*ft_last(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

int	get_new_line(t_list *list)
{
	char	*str;

	if (!list || !list->str)
		return (0);
	while (list)
	{
		str = list->str;
		while (*str)
		{
			if (*str == '\n')
				return (1);
			str++;
		}
		list = list->next;
	}
	return (0);
}

void	create_list(t_list **list, int fd)
{
	int		i;
	char	*str;
	t_list	*new;

	while (!get_new_line(*list))
	{
		str = malloc(sizeof(char) * BUFFER_SIZE + 1);
		i = read(fd, str, BUFFER_SIZE);
		str[i] = '\0';
		if (i == 0)
		{
			free(str);
			str = NULL;
			return ;
		}
		new = (t_list *)malloc(sizeof(t_list));
		if (!new || !str)
			return ;
		if (ft_last(*list))
			ft_last(*list)->next = new;
		else
			*list = new;
		new->str = str;
		new->next = NULL;
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*line;

	if (fd < 0 || read(fd, NULL, 0) == -1 || BUFFER_SIZE <= 0)
	{
		free_everything(&list, NULL, NULL);
		return (NULL);
	}
	create_list(&list, fd);
	if (!list)
		return (NULL);
	line = get_next_line_utils(list);
	rest_of_str(&list);
	return (line);
}
