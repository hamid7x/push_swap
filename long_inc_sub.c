#include <stdio.h>

int	binary_search(int tails[], int value, int size)
{
	int	start;
	int	end;
	int	mid;

	start = 0;
	end = size;
	while (start < end)
	{
		mid = (start + end) / 2;
		if (tails[mid] > value)
			end = mid;
		else
			start = mid + 1;
	}
	return (start);
}

void	reverse_lis(int lis[], int len)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < len / 2)
	{
		tmp = lis[i];
		lis[i] = lis[len - i - 1];
		lis[len - i - 1] = tmp;
		i++;
	}
}

void	build_lis(int arr[], int lis[], int parent[], int last_index)
{
	int	i;

	i = 0;
	while (last_index != -1)
	{
		lis[i] = arr[last_index];
		last_index = parent[last_index];
		i++;
	}
	reverse_lis(lis, i);
}

void	lis_init(int *tails_indx, int *parent, int *lis_len)
{
	tails_indx[0] = 0;
	parent[0] = -1;
	*lis_len = 1;
}

void	lis_handle(int arr[], int size, int lis[], int *lis_len)
{
	int tails[size];
	int tails_indx[size];
	int parent[size];
	int	pos;
	int	i;
	int	last_index;

	lis_init(tails_indx, parent, lis_len);
	tails[0] = arr[0];
	i = 1;
	while(i < size)
	{
		pos = binary_search(tails, arr[i], *lis_len);
		tails[pos] = arr[i];
		tails_indx[pos] = i;
		if (pos > 0)
			parent[i] = tails_indx[pos - 1];
		else
			parent[i] = -1;
		if (*lis_len == pos)
			(*lis_len)++;
		i++;
	}
	last_index = tails_indx[*lis_len - 1];
	build_lis(arr, lis, parent, last_index);
}
