#include <stdio.h>

int	binary_search(int lis[], int size, int target)
{
	int	start;
	int	mid;
	int	end;

	start = 0;
	end = size;
	while(start < end)
	{
		mid = (start + end) / 2;
		if (lis[mid] >= target)
			end = mid;
		else
			start = mid + 1;
	}
	return start;
}

void	longest_increasing_subsequence(int arr[], int size)
{
	int	lis[size];
	int	lis_len;
	int	i;
	int	pos;

	lis[0] = arr[0];
	lis_len = 1;
	i = 1;
	while(i < size)
	{
		if (arr[i] >= lis[lis_len - 1])
		{
			lis[lis_len] = arr[i];
			lis_len++;
		}
		else
		{
			pos = binary_search(lis, lis_len, arr[i]);
			lis[pos] = arr[i];
		}
	 	i++;
	}
	for(int i=0;i<lis_len;i++)
		printf("%d ",lis[i]);
}

int main()
{
	int arr[]= {10,9,2,5,3,7,101,18};
	longest_increasing_subsequence(arr,8);
}
