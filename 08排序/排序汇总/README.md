# 排序

> 稳定性是指排序过程中，原来相同的元素保持原来的相对位置

> 比如 a[i] = a[j] ，且 i<j , 排序后 i<j 依然成立

## 1、插入排序

### (1) 直接插入排序

> 时间复杂度：O(n^2)，最好 O(n)

> 空间复杂度：O(1)

> 稳定性：稳定

- 思路：
  将开头元素视作已排序
  执行下述过程，直到未排序过程消失：

1. 取出未排序部分的开头元素赋给变量 v
2. 在已排序部分，将所有比 v 大的元素向后移动一位
3. 将已取出的元素 v 插入空位

- <img src="https://img-blog.csdnimg.cn/20200610212716370.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNjQwMDA5,size_16,color_FFFFFF,t_70" width="50%">

```cpp
void InsertSort(int a[], int len) {
	for (int i=1; i<len; i++) {
		int v=a[i];
		for (int j=i-1; v<a[j];j--)
            a[j+1]=a[j]; // 后移
        a[j+1]=v;
	}
}
```

### (2) 希尔排序

> 时间复杂度：平均 O(n^1.3)，最坏 O(n^2)

> 空间复杂度：O(1)

> 稳定性：不稳定

**缩小增量法**

- n 个记录，增量为 di，则分组
  - 下标 0, di, 2di, 3di, …… 为 1 组
  - 下标 1, di +1, 2di +1, 3di +1, …… 为 1 组
  - 下标 2, di +2, 2di +2, 3di +2, …… 为 1 组
  - …… …… …… ……
  - 下标 di-1, di+di -1, 2di+di -1, …… 为 1 组
- <img src="https://img-blog.csdnimg.cn/20200611095637945.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNjQwMDA5,size_16,color_FFFFFF,t_70" width="70%">

思路：

- 增量为 d1 时，在各组内，进行排序
- 减小增量，重新分组，组内排序
  - 减小增量：初始：d1 = n/2，则模式：di+1 = di /2
- 重复第 2 步， 直到 di==1，所有记录在同一组，组内排序
  - 排序均为直接插入排序
- <img src="https://img-blog.csdnimg.cn/20200611095957860.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNjQwMDA5,size_16,color_FFFFFF,t_70" width="50%">

```cpp
// ? 按照 ShellSort 定义写出
void shellSort1(int a[], int n) {
    int i, j, k, gap;
    for (gap = n / 2; gap > 0; gap /= 2)
        for (i = 0; i < gap; i++)                   // 分组
            for (int j = i + gap; j < n; j += gap)  // 组内插入排序
                if (a[j] < a[j - gap]) {            // 直接插入排序
                    int v = a[j];
                    for (int k = j - gap; k >= 0 && a[k] > v; k -= gap)
                        a[k + gap] = a[k];  // 后移
                    a[k + gap] = v;
                }
}

// ? 优化
// - 上述 i 的作用是为了确认 j 的位置，并与组内元素比较
// - 明显每次 gap 与 j-gap 就是组内比较，不需要再分组
void shellSort(int a[], int n) {
    int j, k, gap;
    for (gap = n / 2; gap > 0; gap /= 2)
        for (j = gap; j < n; j++)
            if (a[j] < a[j - gap]) {
                int v = a[j];
                for (int k = j - gap; k >= 0 && a[k] > v; k -= gap)
                    a[k + gap] = a[k];  // 后移
                a[k + gap] = v;
            }
}
```

## 2、交换排序

### (3) 冒泡排序

> 时间复杂度：平均 O(n^2)，最坏 O(n^2)，最好 O(n)

> 空间复杂度：O(1)

> 稳定性：稳定

- 思路：
  重复执行下述处理，直到数组中不包含顺序相反的相邻元素：
  1、从数组开头开始依次比较相邻两个元素，如果大小关系相反则交换位置

- <img src="https://img-blog.csdnimg.cn/20200610213746499.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNjQwMDA5,size_16,color_FFFFFF,t_70" width="50%">

后面类推

```cpp
void BubbleSort(int a[], int len){
	for (int i=0; i<len; i++){
		for (int j=i+1; j<len; j++){
			if (a[i]>a[j]){
				int temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
		}
	}
}
```

### (4) 快速排序

> 时间复杂度：平均 O(nlogn)，最坏 O(n^2)

> 空间复杂度：平均 O(logn)，最坏 O(n)

> 稳定性：不稳定

- 思路：
  以整个数组为对象执行 QuickSort
  QuickSort 流程如下：
  1、通过分割将对象局部数组分割为前后两个局部数组
  2、对前半部分的局部数组执行 QuickSort
  3、对后半部分的局部数组执行 QuickSort

- 第 1 趟快排：

  - 从待排序码中，选出 1 个 K（如 R0.key ）
    - 将小于 k 的记录移动到左边（左子表），
    - 大于 k 的记录移动到右边（右子表），
    - 将 k 放在左、右两个子表的分界处
  - 左游历下标：i=0， 右游历下标：j=n-1,  
     取出分区基准：temp=R[0]
    - 初始空位 R[0]：在左表中，即 R[i]
  - 重复以下两种扫描，**直到 i==j** （**空位置在左，则 j 扫描；空位置在右，则 i 扫描**

    - j 向左扫描，直到 R[ j].key < temp.key，
      将 R[ j]移动到空位 R[i]中，则 R[j]为空，令 i++
    - i 向右扫描，直到 R[i].key > temp.key，
      将 R[i]移动到空位 R[ j]中，则 R[i]为空，令 j - -

  - 将“分区基准” temp，放到空位 R[i]中

    <img src="https://img-blog.csdnimg.cn/20200611111724246.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNjQwMDA5,size_16,color_FFFFFF,t_70" width="50%">
    <img src="https://img-blog.csdnimg.cn/2020061111183986.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNjQwMDA5,size_16,color_FFFFFF,t_70" width="50%">

- 第 2 趟快排：
  - 对 K 左、右两个字表，分别执行 1 趟快排 - 4 个子表
    … …
- 直到：各子表长度 ≤1

  - <img src="https://img-blog.csdnimg.cn/20200611111925390.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNjQwMDA5,size_16,color_FFFFFF,t_70" width="50%">
  - <img src="https://img-blog.csdnimg.cn/20200611111954958.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNjQwMDA5,size_16,color_FFFFFF,t_70" width="50%">
  - <img src="https://img-blog.csdnimg.cn/20200611112035856.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNjQwMDA5,size_16,color_FFFFFF,t_70" width="50%">

```cpp
// ? 快排划分
int Partition(int a[], int l, int r) {
    int p = a[l];
    while (l < r) {                      // l != r
        while (l < r && a[r] >= p) --r;  // r 向左扫描
        a[l] = a[r];
        while (l < r && a[l] <= p) ++l;  // l 向右扫描
        a[r] = a[l];
    }
    a[l] = p;
    return l;
}

// ? 快速排序
void QuickSort(int a[], int l, int r) {
    if (l < r) {
        int p = Partition(a, l, r);
        QuickSort(a, l, p - 1);
        QuickSort(a, p + 1, r);
    }
}

// ? 三数取中优化，此版本快的飞起
// https://www.cnblogs.com/chengxiao/p/6262208.html
// - 左端、中间、右端三个数，然后进行排序，将中间数作为枢纽值
void QuickSort(int a[], int l, int r) {
    int mid = a[(l + r) / 2];
    int i = l, j = r;
    do {
        while (a[i] < mid) i++;
        while (a[j] > mid) j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    } while (i <= j);
    if (l < j) QuickSort(a, l, j);
    if (i < r) QuickSort(a, i, r);
}
```

## 3、选择排序

### (5) 简单选择排序

> 时间复杂度：平均 O(n^2)，最坏 O(n^2)

> 空间复杂度：O(1)

> 稳定性：不稳定

思路：

- 重复执行 N-1 次 下述处理：
  1. 找出未排序部分最小值的位置 minj
  2. 将 minj 位置的元素与未排序部分的起始元素交换
- <img src="https://img-blog.csdnimg.cn/2020061021342975.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNjQwMDA5,size_16,color_FFFFFF,t_70" width="50%">

```cpp
void SelectSort(int a[], int len){
	for (int i=0; i<len-1; i++){
		int k=i;
		for (int j=i+1; j<len; j++){
			if (a[j]<a[k]) k=j;
		}
        if (i!=k) swap(a[i],a[k]);
	}
}
```

### (6) 堆排序

> 时间复杂度：平均 O(nlogn)，最坏 O(nlogn)，最好 n(nlogn)

> 空间复杂度：O(1)

> 稳定性：不稳定

思路：

- 将待排序数据建立成大根堆

  - 将待排序记录建成 1 个完全二叉树（**从左往右**插入），再“**从后向前**”依次调整 sift  
    <img src="https://img-blog.csdnimg.cn/2020061110281671.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNjQwMDA5,size_16,color_FFFFFF,t_70" width="50%">
  - sift（待调整：x）：**就是让其满足大根堆**
    - 判断“待调整 x”是否 >左孩子 && >右孩子
      - 是，则无需调整，结束
      - 否，继续“调整 x”，即：重复，直到 x 与孩子满足堆序性，或 x 成为叶子
  - 从**最后结点的父亲**开始，最后结点下标：n-1 父亲下标 p= (n-1-1)/2
    - “从后向前”：依次调整 p, p-1, p-2, …, 0
      <img src="https://img-blog.csdnimg.cn/20200611103428103.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNjQwMDA5,size_16,color_FFFFFF,t_70" width="50%">
    - 之后 sift (3)，sift(2)，sift(1)，sift(0)，构成大根堆

- 重复：选出最大值（堆顶）、并**调整**剩余部分（**较大的孩子上升，空位置下降**
  - <img src="https://img-blog.csdnimg.cn/20200611104141727.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNjQwMDA5,size_16,color_FFFFFF,t_70" width="50%">
  - <img src="https://img-blog.csdnimg.cn/20200611104232312.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNjQwMDA5,size_16,color_FFFFFF,t_70" width="50%">
  - <img src="https://img-blog.csdnimg.cn/20200611104425928.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNjQwMDA5,size_16,color_FFFFFF,t_70" width="50%">
    以此类推，直到堆无剩余元素
  - <img src="https://img-blog.csdnimg.cn/20200611104756166.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNjQwMDA5,size_16,color_FFFFFF,t_70" width="50%">

```cpp
// - 图解 https://www.cnblogs.com/chengxiao/p/6129630.html

// ? 调整以 k 为根的子树，即 shift 操作
// - 大孩子上升，空位置下降
void HeadAdjust(int a[], int k, int len) {
    int t = a[k];
    for (int i = k * 2 + 1; i < len; i = i * 2 + 1) {
        //  如果左子结点小于右子结点，i指向右子结点
        if (i + 1 < len && a[i] < a[i + 1]) i++;
        //  如果子节点大于父节点，将子节点值赋给父节点（不用进行交换）
        if (a[i] > t) {
            a[k] = a[i];
            k = i;
        } else
            break;
    }
    a[k] = t;  // t 放在最终位置
}

// ? 堆排序
void HeapSort(int a[], int len) {
    int i;
    // - 建立大根堆
    for (i = len / 2 - 1; i >= 0; i--) HeadAdjust(a, i, len);
    // - 交换堆顶堆低元素 + 调整堆结构
    for (i = len - 1; i >= 0; i--) {
        swap(a[i], a[0]);
        HeadAdjust(a, 0, i);
    }
}
```

## 4、其他排序

### (7) 归并排序

> 时间复杂度： O(nlogn) (好、坏、平均)

> 空间复杂度：O(n)

> 稳定性：稳定

思路：

以整个数组为对象执行 mergeSort

- mergeSort：
  1. 将给定包含 n 个元素的局部数组分割成两个局部数组
  2. 对局部数组分别 mergeSort
  3. 通过 merge 将两个已排序的数组整合为一个数组

```cpp
void Merge(int a[], int begin, int mid, int end) {
    int left = begin, right = mid + 1, k = 0;
    int *temp = new int[end - begin + 1];
    //顺序选取两个有序区的较小元素，存储到t数组中
    while (left <= mid && right <= end) {
        //较小的先存入temp中
        if (a[left] <= a[right])
            temp[k++] = a[left++];
        else
            temp[k++] = a[right++];
    }
    //若比较完之后，有序区仍有剩余，则直接复制到t数组中
    while (left <= mid) temp[k++] = a[left++];
    while (right <= end) temp[k++] = a[right++];
    //将排好序的存回arr中
    for (int i = begin, k = 0; i <= end; i++, k++) a[i] = temp[k];
    //删除指针，释放空间
    delete[] temp;
}

// ? 递归
void MergeSort(int a[], int begin, int end){
        if (begin<end) {
                int mid=(begin+end)/2;
                MergeSort(a,begin,mid); // 左侧递归
                MergeSort(a,mid+1,end); // 右侧递归
                Merge(a,begin,mid,end)  // 归并
        }
}

// ? 非递归
// void MergeSort(int a[], int n) {
//     int size = 1, begin, mid, end;
//     while (size <= n - 1) {
//         begin = 0;
//         while (begin + size <= n - 1) {
//             mid = begin + size - 1;
//             end = mid + size;
//             if (end > n - 1)  //第二个序列个数不足size
//                 end = n - 1;
//             Merge(a, begin, mid, end);
//             begin = end + 1;  //下一次归并时第一关序列的下界
//         }
//         size *= 2;  //扩大范围
//     }
// }
```

### (8) 基数排序

> 时间复杂度： O(d(n+r)) d: d 趟分配和收集

> 空间复杂度：O(r) r: r 个队列

> 稳定性：稳定

**看图理解：**

<img src="https://www.runoob.com/wp-content/uploads/2019/03/radixSort.gif">

[代码详见](https://github.com/SukiEva/AlgorithmLearning/blob/master/00数据结构/7%20排序/RadixSort.cpp)

## 5、排序比较

<img src="https://img-blog.csdnimg.cn/20200611112228412.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNjQwMDA5,size_16,color_FFFFFF,t_70" width="50%">
