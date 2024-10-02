/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaskal <aaskal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:25:38 by aaskal            #+#    #+#             */
/*   Updated: 2024/09/14 09:58:09 by aaskal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	free_everything(t_list **list, char *line, t_list *new)
{
	t_list	*tmp;

	if (*list == NULL)
		return ;
	while (*list)
	{
		tmp = (*list)->next;
		free((*list)->str);
		(*list)->str = NULL;
		free(*list);
		*list = tmp;
	}
	*list = NULL;
	if (new)
	{
		if (new->str[0])
			*list = new;
		else
		{
			free(line); 
			line = NULL;
			free(new);
			new = NULL;
		}
	}
}

void	rest_of_str(t_list **list)
{
	t_list	*tmp;
	t_list	*old;
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = NULL;
	old = ft_last(*list);
	str = malloc(sizeof(char) * BUFFER_SIZE + 1);
	tmp = (t_list *)malloc(sizeof(t_list));
	if (!str || !tmp)
		return ;
	while (old->str[i] != '\n' && old->str[i] != '\0')
		i++;
	while (old->str[i] != '\0' && old->str[++i]) 
		str[j++] = old->str[i]; 
	str[j] = '\0';
	tmp->str = str;
	tmp->next = NULL;
	free_everything(list, str, tmp);
}

char	*create_line(t_list *list)
{
	int		len;
	char	*line;

	len = 0;
	if (!list)
		return (NULL);
	len = count_char(list);
	line = malloc(sizeof(char) * len + 1);
	if (!line)
		return (NULL);
	return (line);
}

char	*fill_line(char *line, t_list *list)
{
	int		i;
	char	*str;

	i = 0;
	while (list)
	{
		str = list->str;
		while (*str)
		{
			if (*str == '\n')
			{
				line[i++] = '\n';
				line[i] = '\0';
				return (line);
			}
			line[i] = *str;
			str++;
			i++;
		}
		list = list->next;
		line[i] = '\0';
	}
	return (line);
}

char	*get_next_line_utils(t_list *list)
{
	char	*line;

	line = create_line(list);
	if (!line)
		return (NULL);
	line = fill_line(line, list);
	return (line);
}
