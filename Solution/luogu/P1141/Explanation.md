# P1141 01迷宫

思路：BFS

核心：同一个联通块内的点答案相同

故在BFS时最后将路径上所有点的答案更新一下即可

具体实现时，我选择在BFS中开一个栈（或其他的什么东西）记录所有访问过的点，搜索结束后依次更新答案

``` c++
	while(!record.empty())
    {
        ans[record.top().x][record.top().y] = res;
        record.pop();
    }
```

其余的就是查表和常规BFS了