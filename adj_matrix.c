#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "./my_libft5/libft.h"

typedef struct graph
{
	int v;
	int e;
	int **adj;
} t_graph;


t_graph *fill_in_adj_matrix_from_fd(int fd)
{
	int j;
	int i;
	int u;
	int v;
	char *line;
	char *tmp;
	int n;

	t_graph *G;
//create graph
	if (!(G = (t_graph *)malloc(sizeof(t_graph))))
		return (NULL);
//read 1st line and assign No of vertice and edges 
	get_next_line(fd, &line);
	tmp = line;
	tmp = ft_atoi_backsp(tmp, (&G->v), &n);
	tmp = ft_atoi_backsp(tmp, (&G->e), &n);
	free(line);

	ft_printf("G->v = %d\n", G->v);
	ft_printf("G->e = %d\n", G->e);

//create adjacency matrix and initi with zeros
	G->adj = (int **)malloc(sizeof(int *) * G->v);
	i = 0;
	while (i < G->v)
	{
		G->adj[i] = (int *)malloc(sizeof(int) * G->v);
		i++;
	}
//initialize
	i = 0;
	while (i < G->v)
	{
		j = 0;
		while (j < G->v)
		{
			G->adj[i][j] = 0;
			j++;
		}
		i++;
	}
//read next "e" lines and assign the edges
	i = 0;

	// get_next_line(fd, &line);
	// ft_printf("%s\n", line);
	// tmp = line;
	// tmp = ft_atoi_backsp(tmp, &u, &n);
	// tmp = ft_atoi_backsp(tmp, &v, &n);
	// ft_printf("%d\n", u);
	// ft_printf("%d\n", v);
	// G->adj[u][v] = 1;
	// G->adj[v][u] = 1;
	// free(line);
	while (i < G->e)
	{
		get_next_line(fd, &line);
		// ft_printf("%s\n", line);
		tmp = line;
		tmp = ft_atoi_backsp(tmp, &u, &n);
		tmp = ft_atoi_backsp(tmp, &v, &n);
		G->adj[u][v] = 1;
		G->adj[v][u] = 1;
		free(line);
		i++;
	}
	return (G);
}

void	print_adjacency_matrix(t_graph *G)
{
	int i;
	int j;

	i = 0;
	while (i < G->v)
	{
		ft_printf("%3d :", i);
		j = 0;
		while (j < G->v)
		{
			ft_printf("%3d ", G->adj[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	print_neighbours(t_graph *G)
{
	int i;
	int j;

	i = 0;
	while (i < G->v)
	{
		j = 0;
		ft_printf("%4d :", i);
		while (j < G->v)
		{
			if (G->adj[i][j])
				ft_printf("%3d ", j);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

int main(int argc, char **argv)
{
	t_graph *new_G;
	int fd;
	int i;

	if (argc == 1)
		return (0);
	if ((fd = open(argv[1], O_RDONLY)) < 1)
		return (0);
	new_G = fill_in_adj_matrix_from_fd(fd);
	print_adjacency_matrix(new_G);
	print_neighbours(new_G);

	i = 0;
	while (i < new_G->v)
	{
		free(new_G->adj[i]);
		i++;
	}
	free(new_G->adj);
	free(new_G);
	close(fd);
	return (0);
}