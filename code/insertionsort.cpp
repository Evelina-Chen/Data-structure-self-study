void insertion(int a[], int N)
{
	int i, j;
	for (i = 1; i < N; i++)
	{
		int x = a[i];
		for (j = i-1; j >= 0; j--)
		{
			if (x > a[j])//找到了正确的位置
				break;
			a[j+1] = a[j];
		}
		a[j+1] = x;
		for (int i = 0; i < 5; i++)
		{
			printf("%d ", a[i]);
		}
		printf("\n");
	}
}
