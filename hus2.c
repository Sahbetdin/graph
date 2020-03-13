#include <stdio.h>
#include <stdlib.h>
#include "my_libft5/libft.h"

typedef struct		s_stack
{
	int				data;
	struct s_stack	*next;
}					t_stack;

typedef struct		s_queue
{
	int				*front;
	int				*rear;
	int				n;
}					t_queue;

void	push(t_stack **head, int val);
int		top(t_stack **head);
void	pop(t_stack **head);
void	print_stack(t_stack **head);

void	queue_init(t_queue *Q, int size);
int		queue_is_empty(t_queue *Q);
int		queue_is_full(t_queue *Q);
int		queue_insert(t_queue *Q, int x);
void	queue_print(t_queue *Q);
int		queue_out_first(t_queue *Q);
int		queue_shine_first(t_queue *Q);
void	free_queue(t_queue *Q);

void	initiate_arr(int *adj, int *next, int v)
{
	int i;

	i = 0;
	while (i < v)
	{
		adj[i] = 0;
		next[i] = 0;
		i++;
	}
}

void	print_adj6(int *adj)
{
	int i;

	i = 1;
	printf("adj = %d", adj[1]);
	printf(" %d", adj[2]);
	printf(" %d", adj[3]);
	printf(" %d", adj[4]);
	printf(" %d", adj[5]);
	printf(" %d \n", adj[6]);
}

void	print_adj_next(int *adj, int *next, int n)
{
	int i;

	i = 1;
	while (i <= n)
	{
		printf("adj[%d] = %d, next[%d] = %d \n", i, adj[i], i, next[i]);
		i++;
	}
}

/*
11.03.2020 13:00.
we start with top() element in a stack.
we look into the vertices which can be achieved from
this element. If they were already visited we start looking for
the vertice which wasn't visited. If we don't find one, we pop() the
given element and printf "OUT". If we find it we push it into the
stack and printf IN. To denote that we stepped in, we make adj[k_new] = 1
then we recursively repeat the process.

We need to think recursively...
*/
void	dfs(int *adj, int *next, t_stack **h)
{
	int k;
	int i;
	int k_new;

	if (*h == NULL)
	{
		return;
	}
	else
	{
		k = top(h);
		// printf("\033[1;32mk = %d\n\033[0m", k);
		i = next[k];
		// printf("i_bef = %d\n", i);
		while (adj[adj[i]] == 1 && i != 0)
		{
			// printf("\033[1;31mHERE\n\033[0m");
			i = next[i];
			next[k] = i;
		}
		// printf("i_aft = %d\n", i);
		if (i == 0)
		{
			printf("\033[1;34mOUT = %d\n\033[0m", k);
			pop(h);
		}
		else
		{
			k_new = adj[i];
			printf("\033[1;34mIN = %d\n\033[0m", k_new);
			push(h, k_new);
			adj[k_new] = 1;
 			next[k] = next[i];
		}
		// print_stack(h);
		// print_adj_next(adj, next, 10);
		// printf("~~~~~~~~~~~~~\n");
		dfs(adj, next, h);
	}
}

void	bfs(int *adj, int *next, t_queue *Q)
{
	int k;
	int k_new;
	int i;
	int *fr;

	fr = Q->front;
	while (fr != Q->rear)
	{
		k = *fr;
		while ((i = next[k]) != 0)
		{
			k_new = adj[i];
			if (adj[k_new] != 1)
			{
				queue_insert(Q, k_new);
				adj[k_new] = 1;
			}
			next[k] = next[i];
		}
		fr++;
	}
}

int main(int argc, char **argv)
{
	char *line;
	char *tmp;
	int n, nn;
	int u, v, vv, ee;
	int i, j;
	int fd;
	int *adj;
	int *next;
	int m;
	int start;
	char flag_start;

	if (argc == 1)
		return (0);
	if ((fd = open(argv[1], O_RDONLY)) < 1)
		return (0);
	flag_start = 0;
	get_next_line(fd, &line);
	tmp = line;
	tmp = ft_atoi_backsp(tmp, &vv, &nn);
	tmp = ft_atoi_backsp(tmp, &ee, &nn);
	free(line);

	n = vv + 2 * ee;
	printf("n = %d\n", n);
	adj = (int *)malloc(sizeof(int) * n + 1);
	next = (int *)malloc(sizeof(int) * n + 1);
	initiate_arr(adj, next, n + 1);
	free(adj);
	free(next);
	
	// print_adj_next(adj, next, n);

	printf("vv = %d\n", vv);
	printf("ee = %d\n", ee);


	i = vv + 1;
	m = 1;
	while (m <= ee)
	{
		get_next_line(fd, &line);
		if (ft_strcmp(line, "##start") == 0)
		{
			free(line);
			get_next_line(fd, &line);
			start = ft_atoi(line);
			flag_start = 1;
			printf("START point = %d\n", start);
			free(line);
			if (start > vv) //think about checking starting point (eg, uninitialized)
				return (0); // or initialized afterwards
			continue ;
		}
		tmp = line;
		tmp = ft_atoi_backsp(tmp, &u, &nn);
		tmp = ft_atoi_backsp(tmp, &v, &nn);
		free(line);
		adj[i] = v;
		adj[i + 1] = u;
		next[i] = next[u];
		next[u] = i;
		next[i + 1] = next[v];
		next[v] = i + 1;
		i = i + 2;
		m++;
		printf("u = %d, v = %d\n", u, v);
		// getchar();
	}
	if (flag_start == 0)
	{
		free(adj);
		free(next);
		return (0);
	}
	print_adj_next(adj, next, n);

	t_stack *head;
	int k;

//prerequisites for DFS
	// head = NULL;
	// adj[1] = 1;
	// push(&head, 1);
	// printf("in first %d\n", 1);
	// dfs(adj, next, &head);

//prerequisites for BFS
	t_queue q;
	queue_init(&q, vv);
	queue_insert(&q, start);
	adj[start] = 1;
	bfs(adj, next, &q);
	queue_print(&q);

	// free_queue(&q);
	free(adj);
	free(next);
	return (0);
}







