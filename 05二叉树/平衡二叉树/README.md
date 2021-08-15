# Balanced Binary Tree

简称 AVL 树

- AVL 树：每个结点的左、右子树高度之差的绝对值不超过 1.

<img src="https://img-blog.csdnimg.cn/20200512201440325.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNjQwMDA5,size_16,color_FFFFFF,t_70#pic_center" width="70%">

向 AVL 树中，插入 1 个新结点，会破坏平衡吗？

- 若新结点不改变“以其父亲为根”的子树的高度
    - 不破坏
- 若新结点增加了“以其父亲为根”的子树的高度
  - 若在其某个祖先处，不再向上改变”子树”的高度
    - 不破坏
  - 若向上一直改变子树的高度，且其祖先中有平衡因子>0
    - 破坏平衡

##### 平衡二叉树的调整

定义 **被破坏结点**：插入新结点后，|BF|>1 的结点

###### RR 旋转 （右单旋）

插入的结点在被破坏结点**右子树**的**右子树**上

调整方法：令被破坏结点的右子树成为根结点旋转

<img src="https://img-blog.csdnimg.cn/20200512204023243.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNjQwMDA5,size_16,color_FFFFFF,t_70#pic_center" width="70%">

###### LL 旋转 （左单旋）

插入的结点在被破坏结点的**左子树**的**左子树**上

调整方法：令被破坏结点的左子树成为根结点旋转

<img src="https://img-blog.csdnimg.cn/20200512204220617.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNjQwMDA5,size_16,color_FFFFFF,t_70#pic_center" width="70%">

###### LR 旋转 （左-右双旋）

插入的结点在被破坏结点的**左子树**的**右子树**上

调整方法：

<img src="https://img-blog.csdnimg.cn/20200512204853957.png" width="70%">

如上图，从 ABC 调整为 CBA

<img src="https://img-blog.csdnimg.cn/20200512205023632.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNjQwMDA5,size_16,color_FFFFFF,t_70#pic_center" width="70%">

###### RL 旋转 （右-左双旋）

插入的结点在被破坏结点的**右子树**的**左子树**上

调整方法：

<img src="https://img-blog.csdnimg.cn/20200512205336425.png" width="70%">

如上图，从 ABC 调整为 CAB

<img src="https://img-blog.csdnimg.cn/20200512205444331.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNjQwMDA5,size_16,color_FFFFFF,t_70#pic_center" width="70%">
