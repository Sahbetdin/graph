#include <stdio.h>
#include <stdlib.h>

# define MAXV 1000 

typedef struct			s_edgenode {
	int y;
	int					weight;
	struct s_edgenode	*next;
}						t_edgenode;

typedef struct 	s_graph{
	t_edgenode	*edges[MAXV + 1];
	int			degree[MAXV + 1];
	int			nvertices;
	int			nedges;
	char		directed;
}				t_graph;

void	initialize_graph(t_graph *g, char directed)
{
	int i;

	g->nvertices = 0;
	g->nedges = 0;
	g->directed = directed;
	for (i = 0; i < MAXV; i++)
		g->degree[i] = 0;
	for (i = 0; i < MAXV; i++)
		g->edges[i] = NULL;
}


void	insert_edge(t_graph *g, int x, int y, char directed)
{
	t_edgenode *p; /* Временный указатель */

	p = (t_edgenode *)malloc(sizeof(t_edgenode)); /* Выделяем память для edgenode*/
	p->weight = 0;
	p->y = y;

	p->next = g->edges[x];
	g->edges[x] = p;
	g->degree[x]++;
	if (directed == 0)
		insert_edge(g, y, x, 1);
	else
		g->nedges++;
}

void	print_graph(t_graph *g)
{
	int			i; /* Счетчик */
	t_edgenode	*p; /* Временный указатель */

	for (i = 0; i < g->nvertices; i++)
	{
		printf("%d: ", i);
		p = g->edges[i];
		while (p != 0)
		{
			printf(" %d", p->y);
			p = p->next;
		}
		printf("\n");
	}
}

void	read_graph(t_graph *g, char directed)
{
	int i;
	int m;
	int x, y;

	initialize_graph(g, directed);
	scanf("%d %d", &(g->nvertices), &m);
	for (i = 0; i < m; i++)
	{
		scanf("%d %d", &x, &y);
		insert_edge(g, x, y, directed);
	}
}

int main(int argc, char **argv)
{
	t_graph	new_G;
	int		fd;
	int		i;

	// if (argc == 1)
	// if ((fd = open(argv[1], O_RDONLY)) < 1)
	// 	return (0);
	read_graph(&new_G, 1);
	print_graph(&new_G);

	// new_G = fill_in_adj_matrix_from_fd(fd);

	return (0);
}