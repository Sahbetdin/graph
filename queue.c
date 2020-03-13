/*
Queue:
FIFO.
1) insert elem
2) delete elem
3) display elem-s
4) check if queue is empty
5) check if queue is full

Firstly, front and rear point to 0.
After inserting one element, rear position will
change.
*/

//Implementing queues with static arrays


//Implementing queues with dynamic arrays
#include <stdio.h>
#include <stdlib.h>

typedef struct s_queue
{
	int *front;
	int *rear;
	int n;
} t_queue;



void	queue_init(t_queue *Q, int size)
{
	int i;

	Q->n = size;
	Q->front = (int *)malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		Q->front[i] = 0;
		i++;
	}
	Q->rear = Q->front; 
}

int		queue_is_empty(t_queue *Q)
{
	if (Q->front == Q->rear)
		return (1);
	else
		return (0);
}

int		queue_is_full(t_queue *Q)
{
	if (Q->rear - Q->front == Q->n)
		return (1);
	else
		return (0);
}

//if successfully inserted, then return 1
//else return 0
int		queue_insert(t_queue *Q, int x)
{
	if (queue_is_full(Q))
	{
		printf("queue is full\n");
		return (0);
	}
	else
	{
		Q->rear[0] = x;
		Q->rear++;
	}
	return (1);
}

void	queue_print(t_queue *Q)
{
	int i;

	i = 0;
	if (queue_is_empty(Q))
	{
		printf("empty\n");
		return ;
	}
	while (Q->front + i < Q->rear)
	{
		printf("%d ", Q->front[i]);
		i++;
	}
	printf("\n");
}

//if could deleted first, then 
// return that element
//else return -1
int		queue_out_first(t_queue *Q)
{
	int elem;
	int i;
	int maxi;

	if (queue_is_empty(Q) == 0)
	{
		maxi = Q->rear - Q->front;
		elem = Q->front[0];
		i = 0;
		while (i < maxi - 1)
		{
			Q->front[i] = Q->front[i + 1];
			i++;
		}
		Q->rear--;
		return (elem);
	}
	else
		return (-1);
}

//returns first element if the queue is not empty
//else returns -1. 
//Could be resolved?
int		queue_shine_first(t_queue *Q)
{
	if (queue_is_empty(Q) == 0)
	{
		return (Q->front[0]);
	}
	else
		return (-1);
}

// int main()
// {
// 	t_queue q;
// 	int n;

// 	n = 5;
// 	queue_init(&q, n);
// 	queue_insert(&q, 2);
// 	queue_insert(&q, 4);
// 	queue_insert(&q, 6);
// 	queue_insert(&q, -4);
// 	queue_insert(&q, -10);
// 	queue_print(&q);
// 	queue_out_first(&q);
// 	queue_out_first(&q);
// 	queue_print(&q);
// 	printf("%d\n", queue_shine_first(&q));
	


// 	free(q.front);
// 	return (0);
// }