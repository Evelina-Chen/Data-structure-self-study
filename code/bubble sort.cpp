 void bubble(int a[], int N) 
 { 
     for (int i = 0; i < N-1; i++)//当i=N-1时，a[N-1]已经是数组的最后一个元素了，没有相邻元素，也不需要继续比较。这也就是思想中所提到的N=1的情况 
     { 
         for (int j = i + 1; j < N; j++) 
         { 
             if (a[i] > a[j]) 
             { 
                 int t; 
                 t = a[i]; 
                 a[i] = a[j]; 
                 a[j] = t; 
             } 
         } 
     } 
 } 
