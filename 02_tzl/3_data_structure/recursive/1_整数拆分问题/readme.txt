所谓整数划分，是指把一个正整数n写成如下形式：

n=m1+m2+m3+....+mi;（其中mi为正整数，并且1<=mi<=n），则{m1,m2,m3,....,mi}为n的一个划分。

如果{m1,m2,m3,....,mi}中的最大值不超过m，即max{m1,m2,m3,....,mi} <= m，则称它属于n的一个m划分。这里我们记n的m划分的个数为f(n,m)；

例如当n=4时，它有5个划分：{4}、{3,1}、{2,2}、{2,1,1}、{1,1,1,1}；

注意：4=1+3和4=3+1被认为是同一个划分。

该问题是求出n的所有划分个数，即f(n,n)。下面我们考虑求f(n,m)的方法。
