#ifndef BF_HEADER_H
# define BF_HEADER_H

# include "libft.h"
#include <stdio.h>
# define STDOUT 1

/*
** bf_parse
*/
void bf_parse(t_dlist **bf, char c);

/*
** bf_operators
*/
void operator_plus(t_dlist **bf);
void operator_minus(t_dlist **bf);

/*
** utils
*/
void init_memmory(t_dlist **bf);
#endif