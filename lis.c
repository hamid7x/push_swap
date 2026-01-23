int	binary_search(int lis[], int size, int target)
{
	int	start;
	int	mid;
	int	end;

	start = 0;
	end = size;
	while(start < end)
	{
		mid = (start + end - 1) / 2;
		if (lis[mid] >= target)
			return mid;
		else if(
			
	}
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
		if (arr[i] > lis[lis_len - 1])
		{
			lis[lis_len] = arr[i];
			lis_len++;
		}
		else
			pos = binary_search(lis, lis_len, arr[i]);
	}
}

int main()
{
	int arr[]={3,1,5,2,4,6};
	longest_increasing_subsequence(arr,6);
}
