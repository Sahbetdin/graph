#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node * next;
};
void	read_graph(struct node *ad[], int no_of_nodes);
void	print_graph(struct node *ad[], int no_of_nodes);
int main()
{
	int i, j, k, nodes;
	printf("Enter the nodes");
	scanf("%d", &nodes);
	struct node *adj[nodes];
	i = 0;
	while (i < nodes)
	{
		adj[i] = NULL;
		i++;
	}
	read_graph(adj, nodes);
	print_graph(adj, nodes);

}

void	read_graph(struct node *ad[], int no_of_nodes)
{
	struct node *new_node;
	struct node *last;
	int i, j, k, val;

	last = NULL;
	i = 0;
	while (i < no_of_nodes)
	{
		printf("\n Enter number of neightbours of %d ", i + 1);
		scanf("%d", &k);
		j = 0;
		while (j < k)
		{
			printf("Enter the value of %d neighbour of %d", j + 1, i + 1);
			scanf("%d", &val);
			new_node = (struct node *)malloc(sizeof(struct node *));
			new_node->data = val;
			new_node->next = NULL;
			if (ad[i] == NULL)
				ad[i] = new_node;
			else
				last = new_node;
			last = new_node;
			j++;
		}
		i++;
	}
}

void	print_graph(struct node *ad[], int no_of_nodes)
{
	struct node *ptr;
	int i, j;

	ptr = NULL;
	i = 0;
	while (i < no_of_nodes)
	{
		ptr = ad[i];
		printf("\nthe neighbours if %d are: ", i + 1);
		while (ptr != NULL)
		{
			printf("%d\t", ptr->data);
			ptr = ptr->next;
		}
		i++;
	}
}