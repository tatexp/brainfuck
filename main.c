#include "libft.h"
#include "bf_header.h"


/*
Команда Brainfuck	Эквивалент на Си	Описание команды
Начало программы	int i = 0;
					char arr[30000];
					memset(arr, 0, sizeof(arr));	выделяется память под 30 000 ячеек с нулевыми начальными значениями
>					i++;							перейти к следующей ячейке
<					i--;							перейти к предыдущей ячейке
+					arr[i]++;						увеличить значение в текущей ячейке на 1
-					arr[i]--;						уменьшить значение в текущей ячейке на 1
.					putchar(arr[i]);				напечатать значение из текущей ячейки
,					arr[i] = getchar();				ввести извне значение и сохранить в текущей ячейке
[					while(arr[i]){					если значение текущей ячейки ноль, перейти вперёд по тексту программы на ячейку, следующую за соответствующей ] (с учётом вложенности)
]					}								если значение текущей ячейки не нуль, перейти назад по тексту программы на символ [ (с учётом вложенности)
*/

//TODO: вложенные циклы, operator ','

void	start(t_dlist **bf, char *str)
{
	int i = 0;
	while (str[i])
	{
		switch (str[i])
		{
		case '[':
			if ((*bf)->content == 0)
				while (str[i] != ']')
					i++;
			else
			{
				start(bf, str + ++i);
				i -= 2;
			}
			break;				
		case ']':
			if ((*bf)->content == 0)
				return ;
			else
				while (i >= 0 && str[i] != '[')
					i--;
			break;
		default:
			bf_parse(bf, str[i]);
			break;
		}
		i++;
	}
}

int		main(int ac, char **av)
{
	t_dlist *bf = NULL;
	int val;

	if (ac == 2)
	{
		ft_dlstadd_back(&bf, ft_dlstnew(0));
		start(&bf, av[1]);
	}
	return (0);
}