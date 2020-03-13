#include <stdio.h>
#include <stdlib.h>

typedef struct		s_stack
{
	int				data;
	struct s_stack	*next;
}					t_stack;


void	push(t_stack **head, int val)
{
	t_stack *tmp;
	t_stack *new_node;

	tmp = *head;
	new_node = (t_stack *)malloc(sizeof(t_stack));
	new_node->next = tmp;
	new_node->data = val;
	*head = new_node;
}

int		top(t_stack **head)
{
	t_stack *tmp;

	tmp = *head;
	if (tmp)
	{
		return (tmp->data);
		printf("top = %d\n", tmp->data);
	}
	else
	{
		return (-1);
		printf("NULL\n");
	}
}

void	pop(t_stack **head)
{
	t_stack *tmp;

	tmp = *head;
	if (tmp)
	{
		*head = tmp->next;
		free(tmp);
	}
}

void	print_stack(t_stack **head)
{
	t_stack *tmp;

	tmp = *head;
	while (tmp)
	{
		printf("%d -> ", tmp->data);
		tmp = tmp->next;
	}
	printf("NULL\n");
}
