# 哈希
## 一、散列
### 1、基本概念
**散列：**
 
 <img src="https://img-blog.csdnimg.cn/20200715200145426.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNjQwMDA5,size_16,color_FFFFFF,t_70" width="50%">


**碰撞：**
 
 <img src="https://img-blog.csdnimg.cn/20200715200248821.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNjQwMDA5,size_16,color_FFFFFF,t_70" width="50%">

**散列函数：**

 <img src="https://img-blog.csdnimg.cn/20200715200340573.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNjQwMDA5,size_16,color_FFFFFF,t_70" width="50%">

**除余法：**

 <img src="https://img-blog.csdnimg.cn/20200715200516454.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNjQwMDA5,size_16,color_FFFFFF,t_70" width="50%">

例子：
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200715201009675.png)
 ![在这里插入图片描述](https://img-blog.csdnimg.cn/20200715200642965.png)
m=16*2=32<br>
p=31<br>
散列函数 h(key)=key%p

 <img src="https://img-blog.csdnimg.cn/20200715200920178.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNjQwMDA5,size_16,color_FFFFFF,t_70" width="50%">


### 2、​线性勘察法（开地址法处理碰撞）
 <img src="https://img-blog.csdnimg.cn/20200715201346320.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNjQwMDA5,size_16,color_FFFFFF,t_70" width="50%">

例子：
![在这里插入图片描述](https://img-blog.csdnimg.cn/20200715201441361.png)
 <img src="https://img-blog.csdnimg.cn/20200715201549656.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNjQwMDA5,size_16,color_FFFFFF,t_70" width="50%">

已知n个关键码具有相同的散列值d，若采用**线性探查法**解决碰撞，则在散列这n个关键码的过程中，共将要发生<font color="red">n(n-1)/2</font>    次碰撞

### 3、拉链法解决碰撞
 
 <img src="https://img-blog.csdnimg.cn/20200715201943887.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNjQwMDA5,size_16,color_FFFFFF,t_70" width="50%">

例子：
 
 <img src="https://img-blog.csdnimg.cn/20200715202142441.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNjQwMDA5,size_16,color_FFFFFF,t_70" width="50%">

平均查找长度ASL：

<img src="https://img-blog.csdnimg.cn/20200715202641565.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNjQwMDA5,size_16,color_FFFFFF,t_70" width="50%">

## 二、常见的三种哈希结构

当我们想使用哈希法来解决问题的时候，我们一般会选择如下三种数据结构。

* 数组
* set（集合）
* map(映射)

这里数组就没啥可说的了，我们来看一下set。

在C++中，set 和 map 分别提供以下三种数据结构，其底层实现以及优劣如下表所示：

|集合 |底层实现 | 是否有序 |数值是否可以重复 | 能否更改数值|查询效率 |增删效率|
|---|---| --- |---| --- | --- | ---|
|std::set |红黑树 |有序 |否 |否 | O(logn)|O(logn) |
|std::multiset | 红黑树|有序 |是 | 否| O(logn) |O(logn) |
|std::unordered_set |哈希表 |无序 |否 |否 |O(1) | O(1)|

std::unordered_set底层实现为哈希表，std::set 和std::multiset 的底层实现是红黑树，红黑树是一种平衡二叉搜索树，所以key值是有序的，但key不可以修改，改动key值会导致整棵树的错乱，所以只能删除和增加。

|映射 |底层实现 | 是否有序 |数值是否可以重复 | 能否更改数值|查询效率 |增删效率|
|---|---| --- |---| --- | --- | ---|
|std::map |红黑树 |key有序 |key不可重复 |key不可修改 | O(logn)|O(logn) |
|std::multimap | 红黑树|key有序 | key可重复 | key不可修改|O(logn) |O(logn) |
|std::unordered_map |哈希表 | key无序 |key不可重复 |key不可修改 |O(1) | O(1)|

std::unordered_map 底层实现为哈希表，std::map 和std::multimap 的底层实现是红黑树。同理，std::map 和std::multimap 的key也是有序的（这个问题也经常作为面试题，考察对语言容器底层的理解）。

当我们要使用集合来解决哈希问题的时候，优先使用unordered_set，因为它的查询和增删效率是最优的，如果需要集合是有序的，那么就用set，如果要求不仅有序还要有重复数据的话，那么就用multiset。

那么再来看一下map ，在map 是一个key value 的数据结构，map中，对key是有限制，对value没有限制的，因为key的存储方式使用红黑树实现的。

其他语言例如：java里的HashMap ，TreeMap 都是一样的原理。可以灵活贯通。

虽然std::set、std::multiset 的底层实现是红黑树，不是哈希表，但是std::set、std::multiset 依然使用哈希函数来做映射，只不过底层的符号表使用了红黑树来存储数据，所以使用这些数据结构来解决映射问题的方法，我们依然称之为哈希法。 map也是一样的道理。

这里在说一下，一些C++的经典书籍上 例如STL源码剖析，说到了hash_set hash_map，这个与unordered_set，unordered_map又有什么关系呢？

实际上功能都是一样一样的， 但是unordered_set在C++11的时候被引入标准库了，而hash_set并没有，所以建议还是使用unordered_set比较好，这就好比一个是官方认证的，hash_set，hash_map 是C++11标准之前民间高手自发造的轮子。

![哈希表6](https://img-blog.csdnimg.cn/20210104235134572.png)