void select(int a[], int N)
{
	for (int i = 0; i <= N-2; i++)
	{
		int mix = a[i];//假设当前值为最小值
		for (int j = i + 1; j < N; j++)
		{
			if (mix > a[j])//找到了新的最小值
			{
				swap(&mix, &a[j]);
			}
		}
		swap(&mix, &a[i]);
	}
}
