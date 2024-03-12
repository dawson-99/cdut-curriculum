### priority_queue用法

- top 访问队头元素

- empty 队列是否为空

- size 返回队列内元素个数

- push 插入元素到队尾 (并排序)

- emplace 原地构造一个元素并插入队列

- pop 弹出队头元素

- swap 交换内容

  ```c++
  //升序队列
  priority_queue <int,vector<int>,greater<int> > q;
  //降序队列
  priority_queue <int,vector<int>,less<int> >q;
  ```

### sort

```c++
升序：sort(begin,end,less<data-type>());//默认
降序：sort(begin,end,greater<data-type>()).
sort(a, a + 5, greater<int>());
```





### 二分查找

        //在a中找到恰好小于key的数的坐标
        int pos1 = lower_bound(a + 1, a + n + 1, key) - a - 1; //因为查找到的是等于key的，所以要减1
        //在c中找到恰好大于key的数的坐标
        int pos2 = upper_bound(c + 1, c + n + 1, key) - c;

### vector

```c++
//在a中的从a.begin()（包括它）到a.end()（不包括它）的元素中查找10，若存在返回其在向量中的位置
find(a.begin(),a.end(),10); 
q.resize(0)
```

![image-20230326165201883](/Users/xuruihang/Library/Application Support/typora-user-images/image-20230326165201883.png)

### 异或

```c++
string s1 = a;
//异或可以让 '0' => '1' , '1' => '0'
s1[i] ^= 1;
//计算更改后的二
```

### 字符

```c++
//这种操作是可以的
for(int k = '0'; k < '3'; k++){

}
```

### Tarjan

```
　　 1 Tarjan(u)//marge和find为并查集合并函数和查找函数
 　　2 {
 　　3     for each(u,v)    //访问所有u子节点v
 　　4     {
　　 5         Tarjan(v);        //继续往下遍历
　　 6         marge(u,v);    //合并v到u上
　　 7         标记v被访问过;
　　 8     }
　　 9     for each(u,e)    //访问所有和u有询问关系的e
　　10     {
　　11         如果e被访问过;
　　12         u,e的最近公共祖先为find(e);
　　13     }
　　14 }
```

![image-20230328163807440](/Users/xuruihang/Library/Application Support/typora-user-images/image-20230328163807440.png)

```c++
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int, int> PII;

const int N = 10010, M = N * 2;

int n, m;
int h[N], e[M], w[M], ne[M], idx;
int dist[N];//每个点和1号点的距离
int p[N];
int res[M];
int st[N];
vector<PII> query[N];//把询问存下来   
// query[i][first][second] first存查询距离i的另外一个点j，second存查询编号idx

void add(int a,int b,int c)
{
    e[idx] = b;
    ne[idx] = h[a];
    w[idx] = c;
    h[a] = idx++;
}

int find(int x)
{
    if(p[x]!=x)p[x] = find(p[x]);
    return p[x];
}

void dfs(int u,int fa)
{
    for(int i=h[u];~i;i=ne[i])
    {
        int j = e[i];
        if(j==fa) continue;
        dist[j] = dist[u]+w[i];
        dfs(j,u);
    }
}

void tarjan(int u)
{
    st[u]=1;//当前路径点标记为1
    // u这条路上的根节点的左下的点用并查集合并到根节点
    for(int i = h[u];~i;i=ne[i])
    {
        int j = e[i];
        if(!st[j])
        {
            tarjan(j);//往左下搜
            p[j] = u;//从左下回溯后把左下的点合并到根节点
        }
    }
    // 对于当前点u 搜索所有和u
    for(auto item:query[u])
    {
        int y = item.first,id = item.second;
        if(st[y]==2)//如果查询的这个点已经是左下的点(已经搜索过且回溯过,标记为2)
        {
            int anc = find(y);//y的根节点
            // x到y的距离 = d[x]+d[y] - 2*d[lca] 
            res[id] = dist[u]+dist[y] - dist[anc]*2;//第idx次查询的结果 res[idx]
        }
    }
    //点u已经搜索完且要回溯了 就把st[u]标记为2 
    st[u] = 2;
}

int main()
{
    cin >> n >> m;
    // 建图
    memset(h,-1,sizeof h);
    for(int i=0;i<n-1;i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        add(a,b,c),add(b,a,c);
    }

    // 存下询问
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin >> a >> b;
        if(a!=b)
        {
            query[a].push_back({b,i});
            query[b].push_back({a,i});
        }
    }
    for(int i=1;i<=n;i++)p[i] = i;

    dfs(1,-1);
    tarjan(1);
    for(int i=0;i<m;i++)cout << res[i] << '\n';//把每次询问的答案输出
    return 0;
}

```

### 公共祖先

```c++
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;

int n, m;
int l[N], r[N], p[N];
int dist[N];

void dfs(int u, int d)
{
    dist[u] = d;
    if (l[u] != -1) dfs(l[u], d + 1);
    if (r[u] != -1) dfs(r[u], d + 1);
}

int get_lca(int a, int b)
{
    if (dist[a] > dist[b]) swap(a, b);
    while (dist[b] > dist[a]) b = p[b];
    while (a != b) a = p[a], b = p[b];
    return a;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T -- )
    {
        scanf("%d%d", &n, &m);
        memset(l, -1, sizeof l);
        memset(r, -1, sizeof r);
        for (int i = 1; i <= n; i ++ )
        {
            int a, b;
            scanf("%d%d", &a, &b);
            l[i] = a, r[i] = b;
            if (a != -1) p[a] = i;
            if (b != -1) p[b] = i;
        }
        dfs(1, 0);

        while (m -- )
        {
            int a, b;
            scanf("%d%d", &a, &b);
            int lca = get_lca(a, b);
            printf("%d\n", dist[a] + dist[b] - dist[lca] * 2);
        }
    }

    return 0;
}
```

### unordered_set

```c++
c.insert("dddd")：向容器添加元素”dddd"；
a.find("eeee")：查找元素"eeee"，返回结果为a.end()则表明没有找到，否则返回所对应元素；
a.count("eeee")：查找元素"eeee"在a中有几个（由于unordered_set中没有相同的元素，所以结果通常为0或1）。
a.size()：返回a中总的元素个数；
a.empty()：判断a中是否为空。
a.erase("aaa")：清除元素"aaa"。
```

### unodered_map

![image-20230401105536241](/Users/xuruihang/Library/Application Support/typora-user-images/image-20230401105536241.png)

```c++
unordered_map<int, int> p;
p.insert({1, 2});
for(auto m : p){
  cout<<m.first<<m.second;
}
```

### 消除游戏

```c++
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int l[N], r[N], st[N], n;
char val[N];
vector<int> q;
inline void push(int x) {
    if (!st[x]) 
        q.push_back(x), st[x] = true;
}

//检查是否为边缘字符
inline void check(int x) {
    if (l[x] == 0 || r[x] == n + 1 || st[x]) return;
    if (val[x] == val[l[x]] && val[x] != val[r[x]]) push(x), push(r[x]);
    if (val[x] == val[r[x]] && val[x] != val[l[x]]) push(x), push(l[x]);
}

int main () {
    scanf("%s", val + 1);
    n = strlen(val + 1);
    //构造链表， 并把所有的边缘字符加入数组
    for (int i = 1; i <= n; i ++) l[i] = i - 1, r[i] = i + 1, check(i);
    while (q.size()) {
        vector<int> t;//保存可能的边缘字符位置
        for (auto &x : q) {
            //删除x结点
            r[l[x]] = r[x], l[r[x]] = l[x];
            //删除x后， x-1和x+1可能变成边缘字符
            t.push_back(l[x]), t.push_back(r[x]);
        }
        q.resize(0);
        for (auto &x : t) 
            if (x >= 1 && x <= n) check(x);
    }
    string s;
    for (int i = 1; i <= n; i ++) {
        if (!st[i]) s.push_back(val[i]);
    }
    cout << (s.size() > 0 ? s : "EMPTY") << endl;
    return 0;
}
```

### 最长树路径

```c++
#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

const int N=10010;

int h[N],w[2*N],ne[2*N],e[2*N],idx;
int ans;

void add(int a,int b,int c)
{
    w[idx]=c,e[idx]=b,ne[idx]=h[a],h[a]=idx++;
}

int dfs(int u,int father)//father表示u的父节点,因为该图为无向图,并且迭代过程中不能回到父节点,所以要特殊标记.
{
    int dist=0;
    int d1=0,d2=0;//因为题目描述中有:注意:路径中可以只包含一个点
    //所以题目中的结果一定不为负数,负的路径由此可以忽略掉
    for(int i=h[u];i!=-1;i=ne[i])
    {
        int j=e[i];
        if(j==father) continue;
        int d=dfs(j,u)+w[i];//求出路径的长度
        dist=max(dist,d);//求f[x]的最大值
        //d1,d2求出以该点为顶点的最长路径
        if(d>=d1) d2=d1,d1=d;//最长路径和次长路径
        else if(d>d2) d2=d;
    }

    ans=max(ans,d1+d2);

    return dist;//返回当前点的f[x];
}

int main()
{
    memset(h,-1,sizeof(h));

    int n;
    scanf("%d",&n);

    for(int i=1;i<n;i++)//n-1条边
    {
        int a,b,w;
        scanf("%d%d%d",&a,&b,&w);
        add(a,b,w),add(b,a,w);
    }

    dfs(1,-1);

    printf("%d",ans);
}
```

