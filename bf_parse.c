#include "bf_header.h"

void bf_parse(t_dlist **bf, char c)
{
	switch (c)
	{
	case '+':
		(*bf)->content++;
		break;
	case '-':
		(*bf)->content--;
		break;
	case '>':
		if ((*bf)->next == NULL)
			ft_dlstadd_back(bf, ft_dlstnew(0));
		*bf = (*bf)->next;
		break;
	case '<':
		*bf = (*bf)->prev;
		break;
	case '.':
		ft_putchar_fd((char)(*bf)->content, STDOUT);
		break;
	case ',': //TODO
		break;
	case '\n':
		break; //do nothing
	case ' ':
		break; //do nothing
	default:
		ft_putstr_fd("Unknown symbol: |", STDOUT);
		ft_putchar_fd(c, STDOUT);
		ft_putstr_fd("|. Programm stopped.\n", STDOUT);
		printf("symbols's code = %d\n", c);
		exit(1);
		break;
	}
}