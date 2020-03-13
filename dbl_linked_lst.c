//6th march 

#include <stdio.h>
#include <stdlib.h>

typedef struct s_dbl
{
	int data;
	struct s_dbl *next; 
	struct s_dbl *prev;
} t_dbl;



//don't erase
t_dbl *create_new_node(int x)
{
	t_dbl *p;

	if (!(p = (t_dbl *)malloc(sizeof(t_dbl))))
		return (NULL);
	p->data = x;
	p->prev = NULL;
	p->next = NULL;
	return (p);
}


void	insert_at_head(t_dbl **t, int x)
{
	t_dbl *new_node;

	new_node = create_new_node(x);
	if (*t == NULL)
	{
		*t = new_node;
		return ;
	}
	(*t)->prev = new_node;
	new_node->next = (*t);
	(*t) = new_node;
}


// t_dbl	*insert_at_head(t_dbl *t, int x)
// {
// 	t_dbl *new_node;

// 	new_node = create_new_node(x);
// 	if (t == NULL)
// 	{
// 		t = new_node;
// 		return (t);
// 	}
// 	t->prev = new_node;
// 	new_node->next = t;
// 	return (new_node);
// }

//no need to return the same node
//thus no need to return any t_dbl
t_dbl	*insert_at_tail(t_dbl *t, int x)
{
	t_dbl *new_node;

	new_node = create_new_node(x);
	if (t == NULL)
	{
		t = new_node;
		// printf("p = %p\n", t);
		return (t);
	}
	while (t->next != NULL)
		t = t->next;
	t->next = new_node;
	new_node->prev = t;
	return (t);
}

void print_dbl(t_dbl *head)
{
	t_dbl *temp;

	temp = head;
	printf("Forward: ");
	while (temp != NULL)
	{
		printf("%d-> ", temp->data);
		temp = temp->next;
	}
	printf("NULL\n");
}

int main()
{
	t_dbl *head;

	head = NULL;

	// head = insert_at_tail(head, 2);
	// print_dbl(head);

	// head = insert_at_tail(head, 3);
	// print_dbl(head);

	// head = insert_at_tail(head, 5);
	// print_dbl(head);

	insert_at_head(&head, 9);
	print_dbl(head);

	insert_at_head(&head, 5);
	print_dbl(head);


	return (0);
}
