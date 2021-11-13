# Binary Search Tree

简称 BST，也称二叉排序树或二叉查找树。

特点：

- 任一结点 > 其左子树的所有结点，
  并且< 其右子树的所有结点；
- 结点的左、右子树，也是二叉排序树；
- 每个结点键值唯一（不能重复）

重要性质：

- **中序遍历二叉排序树得到递增序列**

所以判断 1 棵二叉树是否是二叉排序树？
只要中序遍历，得到递增序列才是。

### 插入

- 若当前树为空，则新结点为根
- 若当前树不空，
  将待插入 x 与根比较；
  - 若 x 等于根，不用插入
  - 若 x 大于根，则去右子树(找位置)；
  - 若 x 小于根，则去左子树(找位置)；

可以总结为：

插入之前，先查找：

- 若找到，不用插入
- 若找不到，则在到达的空位置处，放入 x；

所以最新插入的结点，一定是叶子；

<img src="https://img-blog.csdnimg.cn/20200512165711664.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNjQwMDA5,size_16,color_FFFFFF,t_70#pic_center" width="50%">

<img src="https://img-blog.csdnimg.cn/20200512170217478.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNjQwMDA5,size_16,color_FFFFFF,t_70#pic_center" width="50%">

```cpp
void BST_Insert(BiTree* T, Elemtype k) {
    /* 用 malloc 分配内存创建
    T = (BiTree*)malloc(sizeof(BiTree));
    T->data = k;
    T->lchild = T->rchild = nullptr;
    */
    if (T == nullptr)
        T = new BiTree(k);  // 直接 new ， 自动分配内存
    else if (k == T->data)
        return;
    else if (k < T->data)
        BST_Insert(T->lchild, k);
    else
        BST_Insert(T->rchild, k);
}
```

### 查找

- 从根结点开始，如果树为空，则返回 NULL
- 如果非空，从根结点开始，比较待检索的键值

  - 若相等，则成功；
  - 若小于根，
    则去根的左子树；

  - 若大于根，
    则去根的右子树，

```cpp
BiTree* BST_Search(BiTree* T, Elemtype k) {
    while (T != nullptr && T->data != k) {
        if (T->data > k)
            T = T->lchild;
        else
            T = T->rchild;
    }
    return T;
}
```

### 删除

考虑三种情况：

- ① 要删除叶子结点
  直接删除，并将父结点指针置为 NULL

<img src="https://img-blog.csdnimg.cn/20200512170832794.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNjQwMDA5,size_16,color_FFFFFF,t_70" width="40%">

- ② 删除只有 1 个孩子的结点
  将父结点指针指向要删除结点的孩子结点

<img src="https://img-blog.csdnimg.cn/20200512170956215.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNjQwMDA5,size_16,color_FFFFFF,t_70" width="45%">

- ③ 删除有左右子树的结点
  用另一个结点替代删除的结点：
  - 右子树的最小元素 或者 左子树的最大元素

<img src="https://img-blog.csdnimg.cn/20200512171205732.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNjQwMDA5,size_16,color_FFFFFF,t_70" width="45%">

```cpp
// ? 删除结点
bool DeleteNode(BiTree* T, BiTree* par) {
    BiTree* tmp;
    // - 1. T为叶子结点，直接删除
    if (T->lchild == nullptr && T->rchild == nullptr) {
        if (par == T) {  // 仅有一个结点，并且要删了它
            delete T;
            return false;
        }
        if (par->lchild == T)
            par->lchild = nullptr;
        else
            par->rchild = nullptr;
        delete T;
    }
    // - 2. T左子树为空，用右子树替代当前结点
    else if (T->lchild == nullptr) {
        tmp = T->rchild;
        T->data = tmp->data;
        T->lchild = tmp->lchild;
        T->rchild = tmp->rchild;
        delete tmp;
    }
    // - 2. T右子树为空，用左子树替代当前结点
    else if (T->rchild == nullptr) {
        tmp = T->lchild;
        T->data = tmp->data;
        T->lchild = tmp->lchild;
        T->rchild = tmp->rchild;
        delete tmp;
    }
    // - 3. T左右子树均不为空，用右子树的最小结点替代
    else {
        tmp = T;
        BiTree* minnode = T->rchild;
        while (minnode->lchild != nullptr) {
            tmp = minnode;  // 记录最小结点的父结点
            minnode = minnode->lchild;
        }
        T->data = minnode->data;

        // ! 下面画图可以更好理解
        if (tmp != T)  // while执行，说明T的右子树有左子树
            tmp->lchild =
                minnode
                    ->rchild;  // 让最小结点的右子树（可能存在）跟在其父结点的左边
        else  // T的右子树没有左子树，此时tmp=T
            tmp->rchild = minnode->rchild;  // 右子树的右子树上移
        delete minnode;
    }
    return true;
}

// ? 删除
BiTree* BST_Delete(BiTree* T, Elemtype k) {
    BiTree *p = T, *par = T;
    while (p != nullptr && k != p->data) {
        par = p;
        if (k < p->data)
            p = p->lchild;
        else
            p = p->rchild;
    }
    bool tag = true;
    if (p != nullptr) tag = DeleteNode(p, par);
    if (!tag) return nullptr; // 仅有一个结点
    return T;
}
```

### 平均检索长度 ASL

比较次数：不大于树的深度

最坏平均查找长度 ASL：(n+1)/2

最好 ASL：log2(n) (参考二分查找)

**所有操作的复杂度都是 O(logn)**

<img src="https://img-blog.csdnimg.cn/2020051217150614.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3FxXzQzNjQwMDA5,size_16,color_FFFFFF,t_70#pic_center" width="60%">
