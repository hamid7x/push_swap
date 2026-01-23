#include <stdio.h>

int	longest_incr_sub(int arr[], int size)
{
	int	lis_len[size];

	int i = 0;
	while(i < size)
	{
		int max = 1;
		int j = 0;
		while(j < i)
		{
			if (arr[j] < arr[i])
			{
				int new_len = 1 + lis_len[j];
				if (new_len > max)
					max = new_len;
			}
			j++;	
		}
		lis_len[i] = max;
		i++;
	}
	int max = lis_len[0];
	for(int i = 1; i < size; i++)
	{
		if(lis_len[i] > max)
			max = lis_len[i];
	}
	return max;
}
#include <stdlib.h>
#include <time.h>
int main()
{

	int	arr[] = {3,1,5,2,4,6};
	int len = longest_incr_sub(arr, 6);
	printf("%d",len);

    /*
    const int N = 100000;
    int arr[N];

    // seed random generator
    srand(time(NULL));

    // generate random numbers (range 1..1000)
    for (int i = 0; i < N; i++)
        arr[i] = rand() % 1000 + 1;

    // start timing
    clock_t start = clock();

    int len = longest_incr_sub(arr, N);

    // end timing
    clock_t end = clock();

    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    printf("LIS length: %d\n", len);
    printf("Time taken: %.6f seconds\n", time_spent);
    */
    return 0;
}
