# 数据结构

## 写在前头

这个大概算是自学数据结构的笔记，会（努力）将所有的东西尝试实现之后上传，代码在readme和code文件夹里都有，希望不要咕咕咕。

能力有限，估计会有很多的疏漏和错误，仅供参考，大家一起进步。

用到的网站：[VisuAlgo-通过动画可视化数据结构和算法](https://visualgo.net/en)，强烈推荐。出于版权考虑，笔记和代码会自己写一遍，但是核心思想都来自这个网站。

## 目录

### <a href='#1'>排序</a>

#### <a href='#1.1'>冒泡排序(bubble sort)</a>

#### <a href='#1.2'>选择排序(selection Sort)</a>

#### <a href='#1.3'>插入排序(insertion Sort)</a>

#### <a href='#1.4'>归并排序(Merge Sort)</a>

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

### <a name='1.4'>插入排序(insertion Sort)</a>

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
  
  - 思想：
  
    给定一个N个项目的数组，归并排序将：
  
    1. 将每对单个元素（默认情况下，已排序）归并为2个元素的有序数组，
    2. 将2个元素的每对有序数组归并成4个元素的有序数组，重复这个过程......，
    3. 最后一步：归并2个N / 2元素的排序数组（为了简化讨论，我们假设N是偶数）以获得完全排序的N个元素数组。
  
    简单来讲，就是将数组分为一个一个的小组，先在小组内进行排序，然后合并多个小组，在对小组进行排序。
  
    将小组合并后比较时，每次比较小组的最左侧元素（即最小元素），将较小者取出，然后继续比较。
  
  - 图解：
  
  - ![image](https://github.com/Evelina-Chen/Data-structure-self-study-/blob/master/image/，mergeSort.png)
  
    
  
    