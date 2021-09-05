# 均匀随机数（随机化+拒绝采样）

>作者：kkbill <br>
链接：https://leetcode-cn.com/problems/implement-rand10-using-rand7/solution/cong-zui-ji-chu-de-jiang-qi-ru-he-zuo-dao-jun-yun-/<br>
来源：力扣（LeetCode）

<div class="e1ak08xt1 css-t3oq9f-StyledRenderedMarkdown">
<p>因为是第一次接触到这样的题目，毫无思绪，对官方题解也是“不知道为什么要这么做”。看过一些题解之后才逐渐明白，现在让我自己来写题解，我打算先从简单的开始讲起。</p>

### Part 1

<p>假设已知<code>rand2()</code>可以<strong>均匀</strong>的生成[1,2]的随机数，现在想均匀的生成[1,4]的随机数，该如何考虑？</p>
<p>我想如果你也像我一样第一次接触这个问题，那么很可能会这么考虑——令两个<code>rand2()</code>相加，再做一些必要的边角处理。如下：</p>

```java
rand2() + rand2() = ? ==> [2,4]
   1    +   1     = 2
   1    +   2     = 3
   2    +   1     = 3
   2    +   2     = 4

// 为了把生成随机数的范围规约成[1,n]，于是在上一步的结果后减1
(rand2()-1) + rand2() = ? ==> [1,3]
   0       +   1     = 1
   0       +   2     = 2
   1       +   1     = 2
   1       +   2     = 3
```

<p>可以看到，使用这种方法处理的结果，最致命的点在于——其<strong>生成的结果不是等概率的</strong>。在这个简单的例子中，产生2的概率是50%，而产生1和3的概率则分别是25%。原因当然也很好理解，由于某些值会有多种组合，因此仅靠简单的相加处理会导致结果不是等概率的。</p>
<p>因此，我们需要考虑其他的方法了。</p>
<p>仔细观察上面的例子，我们尝试对 <code>(rand2()-1)</code> 这部分乘以 2，改动后如下：</p>

```java
(rand2()-1) × 2 + rand2() = ? ==> [1,3]
   0            +   1     = 1
   0            +   2     = 2
   2            +   1     = 3
   2            +   2     = 4
```


<p>神奇的事情发生了，奇怪的知识增加了。通过这样的处理，得到的结果恰是[1,4]的范围，并且每个数都是等概率取到的。因此，使用这种方法，可以通过<code>rand2()</code>实现<code>rand4()</code>。</p>
<p>也许这么处理只是我运气好，而不具有普适性？那就多来尝试几个例子。比如：</p>

```java
(rand9()-1) × 7 + rand7() = result
     a               b
```

<p>为了表示方便，现将<code>rand9()-1</code>表示为a，将<code>rand7()</code>表示为b。计算过程表示成二维矩阵，如下：</p>
<p align="center"><img src="https://pic.leetcode-cn.com/b3a6cfbc8e1c07a46db94f2af7b45935daf0b65c26649ce1b564e6ccfdf5cecf-image.png" alt="image.png" onerror="this.src='data:image/svg+xml,%3Csvg height=\'150\' viewBox=\'0 0 150 150\' width=\'150\' xmlns=\'http://www.w3.org/2000/svg\'%3E%3Cpath d=\'m2465 2286.42347-18.95363-18.92555-50.0112 43.79935-24.62708-24.5906-33.41155 24.5906-22.99654-17.22567v-73.0716c0-2.20914 1.79086-4 4-4h142c2.20914 0 4 1.79086 4 4zm-122-25.59081c5.52285 0 10-4.47052 10-9.98518 0-5.51467-4.47715-9.98519-10-9.98519s-10 4.47052-10 9.98519c0 5.51466 4.47715 9.98518 10 9.98518zm122 40.89296v61.27438c0 2.20914-1.79086 4-4 4h-142c-2.20914 0-4-1.79086-4-4v-53.62625l22.99654 17.22567 33.41155-24.5906 24.62708 24.5906 50.0112-43.79935z\' fill=\'%23eee\' fill-rule=\'evenodd\' transform=\'translate(-2315 -2217)\'/%3E%3C/svg%3E'; "></p>
<p>可以看到，这个例子可以等概率的生成[1,63]范围的随机数。再提炼一下，可以得到这样一个规律：</p>

>已知 rand_N() 可以等概率的生成[1, N]范围的随机数<br>
那么：<br>
(rand_X() - 1) × Y + rand_Y() ==> 可以等概率的生成[1, X * Y]范围的随机数<br>
即实现了 rand_XY()



<h3>Part 2</h3>
<p>那么想到通过<code>rand4()</code>来实现<code>rand2()</code>呢？这个就很简单了，已知<code>rand4()</code>会均匀产生[1,4]的随机数，通过取余，再加1就可以了。如下所示，结果也是等概率的。</p>

```java
rand4() % 2 + 1 = ?
   1 % 2    + 1 = 2
   2 % 2    + 1 = 1
   3 % 2    + 1 = 2
   4 % 2    + 1 = 1
```


<p>事实上，只要<code>rand_N()</code>中N是2的倍数，就都可以用来实现<code>rand2()</code>，反之，若N不是2的倍数，则产生的结果不是等概率的。比如：</p>

```java
rand6() % 2 + 1 = ?
   1 % 2    + 1 = 2
   2 % 2    + 1 = 1
   3 % 2    + 1 = 2
   4 % 2    + 1 = 1
   5 % 2    + 1 = 2
   6 % 2    + 1 = 1

rand5() % 2 + 1 = ?
   1 % 2    + 1 = 2
   2 % 2    + 1 = 1
   3 % 2    + 1 = 2
   4 % 2    + 1 = 1
   5 % 2    + 1 = 2
```

<h3>Part 3</h3>
<p>ok，现在回到本题中。已知<code>rand7()</code>，要求通过<code>rand7()</code>来实现<code>rand10()</code>。</p>
<p>有了前面的分析，<strong>要实现<code>rand10()</code>，就需要先实现<code>rand_N()</code>，并且保证N大于10且是10的倍数。这样再通过<code>rand_N() % 10 + 1</code> 就可以得到[1,10]范围的随机数了</strong>。</p>
<p>而实现<code>rand_N()</code>，我们可以通过part 1中所讲的方法对<code>rand7()</code>进行改造，如下：</p>

`(rand7()-1) × 7 + rand7()  ==> rand49()`

<p>但是这样实现的N不是10的倍数啊！这该怎么处理？这里就涉及到了“<strong>拒绝采样</strong>”的知识了，也就是说，如果某个采样结果不在要求的范围内，则丢弃它。基于上面的这些分析，再回头看下面的代码，想必是不难理解了。</p>

```java
class Solution extends SolBase {
    public int rand10() {
        while(true) {
            int num = (rand7() - 1) * 7 + rand7(); // 等概率生成[1,49]范围的随机数
            if(num <= 40) return num % 10 + 1; // 拒绝采样，并返回[1,10]范围的随机数
        }
    }
}
```

### Part 4: 优化

<p>这部分具体的代码是参考官方题解的，不过是我自己在理解了part 1和part 2之后才看懂的，一开始看真不知道为什么（/(ㄒoㄒ)/~~...</p>
<p>根据part 1的分析，我们已经知道<code>(rand7() - 1) * 7 + rand7()</code> 等概率生成[1,49]范围的随机数。而由于我们需要的是10的倍数，因此，不得不舍弃掉[41, 49]这9个数。优化的点就始于——我们能否利用这些范围外的数字，以减少丢弃的值，提高命中率总而提高随机数生成效率。</p>

```java
class Solution extends SolBase {
    public int rand10() {
        while(true) {
            int a = rand7();
            int b = rand7();
            int num = (a-1)*7 + b; // rand 49
            if(num <= 40) return num % 10 + 1; // 拒绝采样

            a = num - 40; // rand 9
            b = rand7();
            num = (a-1)*7 + b; // rand 63
            if(num <= 60) return num % 10 + 1;

            a = num - 60; // rand 3
            b = rand7();
            num = (a-1)*7 + b; // rand 21
            if(num <= 20) return num % 10 + 1;
        }
    }
}
```

</div>
