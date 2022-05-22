#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct		s_dlist
{
	// void			*content; //need to malloc
	int				content;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
t_dlist	*ft_dlstnew(int content);
void	ft_dlstadd_back(t_dlist **dlst, t_dlist *new);

#endif