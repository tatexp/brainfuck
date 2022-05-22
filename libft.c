#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		while (*s)
			ft_putchar_fd(*s++, fd);
}

t_dlist	*ft_dlstnew(int content)
{
	t_dlist	*dlst;

	dlst = (t_dlist *)malloc(sizeof(t_dlist));
	if (!dlst)
		return (dlst = NULL);
	dlst->content = content;
	dlst->next = NULL;
	dlst->prev = NULL;
	return (dlst);
}

void	ft_dlstadd_back(t_dlist **dlst, t_dlist *new)
{
	t_dlist	*tmp;

	tmp = *dlst;
	if (new && dlst)
	{
		if (*dlst)
		{
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = new;
			new->prev = tmp;
		}
		else
			*dlst = new;
	}
}