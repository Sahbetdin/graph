#include <stdio.h>
#include <stdlib.h>
#include "my_libft5/libft.h"

typedef struct		s_stack
{
	int				data;
	struct s_stack	*next;
}					t_stack;


void	push(t_stack **head, int val);
int		top(t_stack **head);
void	pop(t_stack **head);
void	print_stack(t_stack **head);


void	initiate_arr(int *adj, int *next, int v)
{
	int i;

	i = 0;
	while (i < v + 1)
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

char is_summ(int *adj)
{
	int i;
	int s;

	i = 1;
	s = 0;
	while (i <= 6)
	{
		s += adj[i];
		i++;
	}
	if (s == 6)
		return (1);
	else
		return (0);
}

// void	dsf(int *adj, int *next, int *k)
// {
// 	int i;

// 	i = next(*k);
// 	adj[*k] = 1;


// }

// void	dsf(int *adj, int *next, int *k)
// {
// 	int i;
// 	int cur; //current node

// 	print_adj6(adj);
// 	if (is_summ(adj) == 1)
// 		return ;
// 	else
// 	{
// 		i = *k;
// 		adj[*k] = 1;
// 		printf("visited %d\n", adj[i]);
// 		while (next[i])
// 		{
// 			i = next[i];
// 			dsf(adj, next, &i);
// 		}

// 	}
// }


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

	if (argc == 1)
		return (0);
	if ((fd = open(argv[1], O_RDONLY)) < 1)
		return (0);

	get_next_line(fd, &line);
	tmp = line;
	tmp = ft_atoi_backsp(tmp, &vv, &nn);
	tmp = ft_atoi_backsp(tmp, &ee, &nn);
	free(line);

	n = vv + 2 * ee;
	printf("n = %d\n", n);

	adj = (int *)malloc(sizeof(int) * n + 1);
	next = (int *)malloc(sizeof(int) * n + 1);
	initiate_arr(adj, next, n);
	// print_adj_next(adj, next, n);

	printf("vv = %d\n", vv);
	printf("ee = %d\n", ee);

	i = vv + 1;
	m = 1;
	while (m <= ee)
	{
		get_next_line(fd, &line);
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
	print_adj_next(adj, next, n);

	int k;
	// k = 1;
	// while (k <= vv)
	// {
	// 	printf("%d:   ", k);
	// 	i = k;
	// 	while (next[i])
	// 	{
	// 		i = next[i];
	// 		printf("%d  ", adj[i]);		
	// 	}
		printf("\n");
	// 	k++;
	// }

	t_stack *head;
	head = NULL;
	k = 1;
	int count;
////
	if (adj[k] == 1 && next[k] == 0)
	{
		printf("popping k = %i\n", k);
		pop(&head);
	}
	if (adj[k] == 0)
	{
		adj[k] = 1;
		push(&head, k);
		i = next[k];
		next[k] = next[i];
		k = adj[i];
	}
	print_adj_next(adj, next, n);
	print_stack(&head);
	printf("k = %d\n", k);
//////////
	if (adj[k] == 1 && next[k] == 0)
	{
		printf("popping k = %i\n", k);
		pop(&head);
	}
	if (adj[k] == 0)
	{
		adj[k] = 1;
		push(&head, k);
		i = next[k];
		next[k] = next[i];
		k = adj[i];
	}
	print_adj_next(adj, next, n);
	print_stack(&head);
	printf("k = %d\n", k);
///////////
	if (adj[k] == 1 && next[k] == 0)
	{
		printf("popping k = %i\n", k);
		pop(&head);
	}
	if (adj[k] == 0)
	{
		adj[k] = 1;
		push(&head, k);
		i = next[k];
		next[k] = next[i];
		k = adj[i];
	}
	print_adj_next(adj, next, n);
	print_stack(&head);
	printf("k = %d\n", k);
// /////
	if (adj[k] == 0)
	{
		adj[k] = 1;
		push(&head, k);
		i = next[k];
		next[k] = next[i];
		if (adj[k] == 1 && next[k] == 0)
		{
			printf("popping k = %i\n", k);
			pop(&head);
		}
		else
			k = adj[i];
	}
	print_adj_next(adj, next, n);
	print_stack(&head);
	printf("k = %d\n", k);
// ///////////////
// 	if (adj[k] == 1 && next[k] == 0)
// 	{
// 		printf("popping k = %i\n", k);
// 		pop(&head);
// 	}
// 	if (adj[k] == 0)
// 	{
// 		adj[k] = 1;
// 		push(&head, k);
// 		i = next[k];
// 		next[k] = next[i];
// 		k = adj[i];
// 	}
// 	print_adj_next(adj, next, n);
// 	print_stack(&head);
// 	printf("k = %d\n", k);
//////////////
	count = 0;
	// while (count < 7)
	// {
	// 	if (next[k] == 0)
	// 	{
	// 		pop(&head);
	// 		k = top(&head);
	// 	}
	// 	if (adj[k] == 0)
	// 	{
	// 		adj[k] = 1;
	// 		push(&head, k);
	// 		i = next[k];
	// 		next[k] = next[i];
	// 		k = adj[i];
	// 	}
	// 	else
	// 	{
	// 		i = next[k];
	// 		next[k] = next[i];
	// 	}
	// 	print_adj_next(adj, next, n);
	// 	print_stack(&head);
	// 	count++;
	// }

	

	// count = 0;
	// while (count < 5)
	// {
	// 	if (adj[k] == 0)
	// 	{
	// 		adj[k] = 1;
	// 		push(&head, k);
	// 		i = next[k];
	// 		next[k] = next[i];

	// 	// printf("k inside = %d %d\n", k, next[k]);
	// 	// 	if (next[k] == 0)
	// 	// 		printf("NOW, k = %d!\n", k);
	// 		k = adj[i];
	// 	}
	// 	else
	// 	{	
	// 		if (next[k] == 0)
	// 			printf("NOW, k = %d!\n", k);

	// 		next[k] = next[next[k]];
	// 	}
	// printf("k = %d %d\n", k, next[k]);
	// printf("i = %d\n", i);
	// 	count++;
	// }



	// printf("n = %d\n", n);
	// int k = 1;
	// dsf(adj, next, &k);
	// adj[1] = 1;
	// adj[2] = 1;
	// adj[3] = 1;
	// adj[4] = 1;
	// adj[5] = 1;
	// adj[6] = 1;
	// printf("is_summ = %d\n", is_summ(adj)); 	

	return (0);
}







