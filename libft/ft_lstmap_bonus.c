/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiparcer <jiparcer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 16:29:35 by jiparcer          #+#    #+#             */
/*   Updated: 2024/10/11 16:50:21 by jiparcer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// a refaire demain avec di psq copy paste
void	*duplicate(void *content)
{
	int	*new_content;

	new_content = malloc(sizeof(int));
	if (new_content == NULL)
		return (NULL);
	*new_content = *(int *)content * 2;
	return (new_content);
}

void	delete_content(void *content)
{
	free(content);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	**current;
	t_list	*next;
	void	*new_content;

	new_lst = NULL;
	current = &new_lst;
	while (lst)
	{
		new_content = f(lst->content);
		if (!new_content && del)
			while (new_lst)
			{
				next = new_lst->next;
				del(new_lst->content);
				free(new_lst);
				new_lst = next;
			return (NULL);
			}
		*current = ft_lstnew(new_content);
		if (!*current)
			return (NULL);
		current = &(*current)->next;
		lst = lst->next;
	}
	return (new_lst);
}
