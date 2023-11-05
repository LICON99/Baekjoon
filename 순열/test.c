#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n;
int arr[10];
typedef struct s_list
{
	int n;
	struct s_list *next;
} t_list;

int cmp(const void *a, const void *b)
{
	if (*(int *)a > *(int *)b)
		return (1);
	else if (*(int *)a > *(int *)b)
		return (-1);
	else
		return (0);
}
void init()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf(" %d", &arr[i]);
}

t_list *newlist(int n)
{
	t_list *tmp;
	tmp = (t_list *)malloc(sizeof(t_list));
	if (!tmp)
		return (0);
	tmp->n = n;
	tmp->next = NULL;
	return (tmp);
}

void push_front(t_list **first, t_list *new)
{
	if (!*first)
	{
		*first = new;
		return;
	}
	new->next = *first;
	*first = new;
}

void push_back(t_list **first, t_list *new)
{
	if (!*first)
	{
		*first = new;
		return;
	}
	while ((*first)->next)
		first = &((*first)->next);
	(*first)->next = new;
}

void calc_res(t_list *first)
{
	size_t res = 0;

	while (first->next)
	{
		res += abs(first->n - first->next->n);
		first = first->next;
	}
	printf("%zu\n", res);
	return;
}

int main(void)
{
	t_list *first;

	init();
	qsort(arr, n, sizeof(arr[0]), cmp);
	first = newlist(arr[0]);
	for (int i = 0; i < n / 2; i++)
	{
		if (i % 2 == 0)
		{
			push_front(&first, newlist(arr[(n - 1) - i]));
			if ((n - 1) - i - 1 >= n / 2)
				push_back(&first, newlist(arr[(n - 1) - (i + 1)]));
		}
		if (i % 2 == 1)
		{
			push_front(&first, newlist(arr[i]));
			if (i + 1 < n / 2)
				push_back(&first, newlist(arr[(i + 1)]));
		}
	}
	// while (first)
	// {
	// 	printf("%d ", first->n);
	// 	first = first->next;
	// }
	// printf("\n");
	calc_res(first);
	return 0;
}