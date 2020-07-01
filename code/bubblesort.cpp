void bubblesort(int a[], int N)
{
	int i, j;
	for (i = 0; i < N - 1; i++)
		for (j = 0; j < N - 1 - i; j++)
			if (a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
}
