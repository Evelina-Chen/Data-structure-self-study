# 数据结构

## 写在前头

这个大概算是自学数据结构的笔记，会（努力）将所有的东西尝试实现之后上传，代码在readme和code文件夹里都有，希望不要咕咕咕。

能力有限，估计会有很多的疏漏和错误，仅供参考，大家一起进步。

因为墙的原因，突然不能看GitHub上的图片了，从归并排序以后的部分的图片可能会出现插入错误的问题，可以从image文件夹中找到对应图片

快速排序学的有点懵，暂缺，等学明白以后会补上

用到的网站：[VisuAlgo-通过动画可视化数据结构和算法](https://visualgo.net/en)，强烈推荐。出于版权考虑，笔记和代码会自己写一遍，但是核心思想都来自这个网站。

## 目录

### <a href='#1'>排序</a>

#### <a href='#1.1'>冒泡排序(bubble sort)</a>

#### <a href='#1.2'>选择排序(selection Sort)</a>

#### <a href='#1.3'>插入排序(insertion Sort)</a>

#### <a href='#1.4'>归并排序(Merge Sort)</a>

#### <a href='#1.5'>快速排序(Quick Sort)**暂缺**</a>

### <a href='#1.6'>计数排序(Counting Sort)</a>

### <a href='#1.7'>基数排序(Radix Sort)</a>

## <a name='1'>排序</a>

### swap函数

在实现排序函数时，有时会用到swap函数，即交换两个数的值，以下是swap函数的具体内容，在排序的具体实现过程中不再重复实现

```
void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
```

### <a name='1.1'>冒泡排序(bubble sort)</a>

- 时间复杂度O(n²)

- 思想：

  对于拥有N个元素的数组，冒泡排序将进行以下操作：

  ①如果元素大小关系不正确（比如将数组从大到小排列时，位于数组左侧（编号较小者）的数字大于右侧），交换这两个数，

  ②比较一对相邻元素，

  ③重复步骤1和2，直到到达数组的末尾（第（N-2）和（N-1）项）

  ④完成一遍上述操作后，最大的元素将在最后的位置。 然后我们将N减少1，并重复上述步骤，直到N = 1

  

  简单来讲，就是重复比较相邻元素，从第0项遍历到第N-1项，这样一来第0项到第N-1项的最大项就会移动到第N-1项的位置，这时N减少1，然后重复比较，直到N=1

- 代码实现：

    ```
    void bubblesort(int a[], int N)
    {
    	for (int i = 0; i < N - 1; i++)//i++等效于N--
    		for (int j = 0; j < N - 1 - i; j++)
    			if (a[j] > a[j + 1])
    				swap(a[j], a[j + 1]);
    }
    ```

    

- 图解：

    ![image](https://github.com/Evelina-Chen/Data-structure-self-study/blob/master/image/bubblesort.png)

- 总迭代次数： N ×（N-1）/ 2

### <a name='1.1'>选择排序(selection Sort)</a>

- 时间复杂度：O(N²)

- 思想：

  对于有N个元素的数组，设 **L = 0** ，选择排序将进行以下操作：

  ①在 **[L ... N-1]** 范围内找出最小项目 X的位置，

  ②用第 **L** 项交换X，

  ③将下限 **L** 增加1并重复步骤1直到 **L = N-2**。

  简单来说就是：

  从第0个到第N-1个元素中找到最小的元素，将最小元素与第0个元素互换位置

  从第1个到第N-1个元素中找到最小的元素（即整个数组倒数第二小的元素），将最小元素与第1个元素互换位置

  以此类推

- 图解：

  ![image](https://github.com/Evelina-Chen/Data-structure-self-study-/blob/master/image/selectionsort.png)

- 代码实现：

  ```
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
  ```

### <a name='1.3'>插入排序(insertion Sort)</a>

- 时间复杂度：O(N²)

- 思想（不太能用文字描述）：

  1.选择一个开始的元素

  2.将下一个元素放到正确的位置（即在前面所有的元素中，选择一个大于前面所有元素，小于后面所有元素的位置插入）

  3.重复1，2步骤

- 图解：

- ![image](https://github.com/Evelina-Chen/Data-structure-self-study-/blob/master/image/insertionSort.png)

- 代码实现：

  ```
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
  ```

  

  

### <a name='1.4'>归并排序(Merge Sort)</a>

  归并排序是分治法的经典应用

  - 思想：
  
    给定一个N个项目的数组，归并排序将：

    1. 将每对单个元素（默认情况下，已排序）归并为2个元素的有序数组，
  2. 将2个元素的每对有序数组归并成4个元素的有序数组，重复这个过程......，
        3. 最后一步：归并2个N / 2元素的排序数组（为了简化讨论，我们假设N是偶数）以获得完全排序的N个元素数组。

    简单来讲，就是将数组分为一个一个的小组，先在小组内进行排序，然后合并多个小组，在对小组进行排序。
    
    将小组合并后比较时，每次比较小组的最左侧元素（即最小元素），将较小者取出，然后继续比较。

  - 图解：

    ![image](https://github.com/Evelina-Chen/Data-structure-self-study-/blob/master/image/mergeSort.png)
  
  - 代码实现：
  
    //实现归并排序对我有些困难，这里引用了https://blog.csdn.net/a130737/article/details/38228369的代码，侵删
    
    ```
    /* Merge sort in C++ */
    #include <cstdio>
    #include <iostream>
     
    using namespace std;
     
    // Function to Merge Arrays L and R into A.
    // lefCount = number of elements in L
    // rightCount = number of elements in R.
    void Merge(int *A,int *L,int leftCount,int *R,int rightCount) {
    	int i,j,k;
     
    	// i - to mark the index of left aubarray (L)
    	// j - to mark the index of right sub-raay (R)
    	// k - to mark the index of merged subarray (A)
    	i = 0; j = 0; k =0;
     
    	while(i<leftCount && j< rightCount) {
    		if(L[i]  < R[j]) A[k++] = L[i++];
    		else A[k++] = R[j++];
    	}
    	while(i < leftCount) A[k++] = L[i++];
    	while(j < rightCount) A[k++] = R[j++];
    }
     
    // Recursive function to sort an array of integers.
    void MergeSort(int *A,int n) {
    	int mid,i, *L, *R;
    	if(n < 2) return; // base condition. If the array has less than two element, do nothing.
     
    	mid = n/2;  // find the mid index.
     
    	// create left and right subarrays
    	// mid elements (from index 0 till mid-1) should be part of left sub-array
    	// and (n-mid) elements (from mid to n-1) will be part of right sub-array
    	L = new int[mid];
    	R = new int [n - mid];
     
    	for(i = 0;i<mid;i++) L[i] = A[i]; // creating left subarray
    	for(i = mid;i<n;i++) R[i-mid] = A[i]; // creating right subarray
     
    	MergeSort(L,mid);  // sorting the left subarray
    	MergeSort(R,n-mid);  // sorting the right subarray
    	Merge(A,L,mid,R,n-mid);  // Merging L and R into A as sorted list.
    	// the delete operations is very important
    	delete [] R;
    	delete [] L;
    }
     
    int main() {
    	/* Code to test the MergeSort function. */
     
    	int A[] = {6,2,3,1,9,10,15,13,12,17}; // creating an array of integers.
    	int i,numberOfElements;
     
    	// finding number of elements in array as size of complete array in bytes divided by size of integer in bytes.
    	// This won't work if array is passed to the function because array
    	// is always passed by reference through a pointer. So sizeOf function will give size of pointer and not the array.
    	// Watch this video to understand this concept - http://www.youtube.com/watch?v=CpjVucvAc3g
    	numberOfElements = sizeof(A)/sizeof(A[0]);
     
    	// Calling merge sort to sort the array.
    	MergeSort(A,numberOfElements);
     
    	//printing all elements in the array once its sorted.
    	for(i = 0;i < numberOfElements;i++)
    	   cout << " " << A[i];
    	return 0;
    }
    ```
    

### <a name='1.5'>快速排序(Quick Sort)暂缺</a>

一定不会咕咕咕的

### <a name='1.6'>计数排序(Counting Sort)</a>

计数排序是不急于比较的排序方法

计数排序适合小范围的数字的排序

- 思想：计算这个范围内每个数字出现的次数，然后一次打印

  比如：所有的数字都在[0,9]范围内，计算每个数字出现的次数,c0,c1,c2...，然后一次输出c0个0，c1个1，c2个2...

- 局限性：

  不适用于数据范围较大的排序

  不适用于数据有小数的排序

- 图解

  ![image](https://github.com/Evelina-Chen/Data-structure-self-study-/blob/master/image/countingsort.png)



### <a name='1.7'>基数排序(Radix Sort)</a>

参考了菜鸟教程：https://www.runoob.com/w3cnote/radix-sort.html

- 思想：

  按位数将数字分组，在对每组的数字进行个位数的比较

- 图解：

  ![image](https://github.com/Evelina-Chen/Data-structure-self-study-/blob/master/image/radixsort.png)

  

