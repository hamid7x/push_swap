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

void	lis_handle(int arr[], int size, int lis[], int *lis_len)
{
	int tails[size];
	int tails_indx[size];
	int parent[size];
	int	pos;
	int	i;

	tails_indx[0] = 0;
	parent[0] = -1;
	tails[0] = arr[0];
	*lis_len = 1;
	i = 1;
	while(i < size)
	{
		if(arr[i] > tails[*lis_len - 1])
		{
			tails[*lis_len] = arr[i];
			tails_indx[*lis_len] = i;
			parent[i] = tails_indx[*lis_len - 1];
			*lis_len += 1;
		}
		else
		{
			pos = binary_search(tails, arr[i], *lis_len);
			tails[pos] = arr[i];
			tails_indx[pos] = i;
			if (pos > 0)
				parent[i] = tails_indx[pos - 1];
			else
				parent[i] = -1;
		}
		i++;
	}
	int last_index = tails_indx[*lis_len - 1];
	int i = 0;
	while (last_index != -1)
	{
		lis[i] = arr[last_index];
		last_index = parent[last_index];
		i++;
	}
	for(int i = 0; i < (*lis_len) / 2; i++)
	{
		int tmp = lis[i];
		lis[i] = lis[*lis_len - i - 1];
		lis[*lis_len - i - 1] = tmp;
	}
}
/*
int main()
{
	int arr[] = {27, 24, 58, 79, 41, 13, 49, 32, 10, 53};
	int lis[10];
	int lis_len;

	lis_handle(arr, 10, lis, &lis_len);
	//for(int i = 0; i < lis_len; i++)
		//printf("%d ",lis[i]);
}
*/
