#include <stdio.h>
#include <stdlib.h>
#include "./my_libft5/libft.h"
#include <fcntl.h>

//adjacent list
typedef struct		ss_list
{
	int				data;
	struct ss_list	*next; 
}					tt_list;

//the nodes of a graph in double linked list
typedef struct		s_graph
{
	int				x;
	tt_list			*edges;
	int				degree;
	char			state;
}					t_graph;


void	ft_create_list_elem(tt_list **t, int val)
{
	tt_list *ptr;
	
	ptr = (tt_list *)malloc(sizeof(tt_list));
	ptr->data = val;
	ptr->next = *t;
	*t = ptr;
}

void	print_t_list(tt_list **t)
{
	tt_list *ptr;

	ptr = *t;
	while (ptr != NULL)
	{
		printf("%d -> ", ptr->data);
		ptr = ptr->next;
	}
	printf("NULL\n");
}

void	init_graph(t_graph *g, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		g[i].x = i;
		g[i].edges = NULL;
		g[i].degree = 0;
		g[i].state = 0;
		i++;
	}
}

//assign
void	init_degrees(t_graph *g)
{
	g[0].degree = 1;
	g[1].degree = 3;
	g[2].degree = 4;
	g[3].degree = 3;
	g[4].degree = 2;
	g[5].degree = 1;
}

void	allocate_edges(t_graph *g)
{
	int i;
	int j;

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < g[i].degree)
		{
			ft_create_list_elem(&g[i].edges, 0);
			j++;
		}
		i++;
	}
}

//закончиили здась
//есть список смежности
//далее не знаю что делать
//открыл Хусяинова стр 400
void	fill_in_edges(t_graph *g)
{

	g[0].edges->data = 1;
	g[1].edges->data = 0;
	g[1].edges->next->data = 2;
	g[1].edges->next->next->data = 3;
	g[2].edges->data = 1;
	g[2].edges->next->data = 3;
	g[2].edges->next->next->data = 4;
	g[2].edges->next->next->next->data = 5;
	g[3].edges->data = 1;
	g[3].edges->next->data = 2;
	g[3].edges->next->next->data = 4;
	g[4].edges->data = 2;
	g[4].edges->next->data = 3;
	g[5].edges->data = 2;
}

/*
4 5 //v e
0 3
0 2
1 2
1 3
2 3

*/

int main(int argc, char **argv)
{
	int		v;
	int		e;
	t_graph	*G;
	int		i;
	int		fd;
	char	*line;
	char	*tmp;
	int		n;

	if (argc == 1)
		return (0);
	if ((fd = open(argv[1], O_RDONLY)) < 1)
		return (0);

	get_next_line(fd, &line);
	tmp = line;
	tmp = ft_atoi_backsp(tmp, &v, &n);
	tmp = ft_atoi_backsp(tmp, &e, &n);
	free(line);

	ft_printf("v = %d\n", v);
	ft_printf("e = %d\n", e);

	G = (t_graph *)malloc(sizeof(t_graph) * v);

	init_graph(G, v);
	init_degrees(G);
	allocate_edges(G);
	fill_in_edges(G);

	i = 0;
	while (i < v)
	{
		print_t_list(&G[i].edges);
		i++;
	}

	// t_list *ttt;
	// ttt = NULL;
	// ft_create_list_elem(&ttt, 4);
	// ft_create_list_elem(&ttt, 6);
	// ft_create_list_elem(&ttt, 10);

	// print_t_list(&ttt);
	
//init edges 


	free(G);
	return (0);
}