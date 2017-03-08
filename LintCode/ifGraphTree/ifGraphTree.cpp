/****************************************************************
    Copyright (C) 2017 Yancey Zhang. All rights reserved.
					      									  
    > File Name:         < ifGraphTree.cpp >
    > Author:            < Yancey Zhang >
    > Mail:              < yanceyzhang2013@gmail.com >
    > Created Time:      < 2017/03/08 >
    > Last Changed: 
    > Description:
****************************************************************/


#include <iostream>
#include <string.h>
#include <stack>
#include <vector>
using namespace std;

// 判断一个图是否是树木
// 树的话肯定是无环的
// 判断图有没有环就行了
bool ifGraphTree(int n, vector<vector<bool> >& b)
{
    bool flag = true;
    stack<int> s;
    if(n <= 0)
        return flag;
    bool visited[n];
    bool ed_visit[n][n];
    for(int i = 0; i < n; i++)
        memset(ed_visit, false, sizeof(ed_visit)/sizeof(bool));
    memset(visited, false, sizeof(visited)/sizeof(bool));
    s.push(0);
    visited[0] = true;
    cout << 0 << " ";
    int numNode = 1;
    while(!s.empty())
    {
        int v = s.top();
        int i = 0;
        for(i = 0; i < n; i++)
        {
            if(v != i && b[v][i] == true)
            {
                if(visited[i] == false)
                {
                    visited[i] = true;
                    ed_visit[i][v] = true;
                    ed_visit[v][i] = true;
                    s.push(i);
                    cout << i << " ";
                    numNode++;
                    break;
                }
                else // 如果访问过这个节点
                {
                    // 如果回溯了原来的路径，则继续
                    if(ed_visit[i][v] == true || ed_visit[v][i] == true)
                        continue;
                    // 若没有，则遇到了环，不是树
                    return false;

                }
            }
        }
        if(i == n)
            s.pop();
    }
    cout << "numNode:" << numNode << endl;
    if(numNode < n)
        return false;
    return flag;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int> > edges;
    vector<int> tmp(2, 0);
    int a, b;
    while(cin >> a >> b)
    {
        tmp[0] = a;
        tmp[1] = b;
        edges.push_back(tmp);
    }
	if(n < 1)
    	return false;
    if(edges.size() < (unsigned int)(n-1))
        return false;
    vector<vector<bool> > Graph(n, vector<bool>(n, false));
    // 构建图
    for(unsigned int i = 0; i < edges.size(); i++)
    {
        Graph[edges[i][0]][edges[i][1]] = true;       
        Graph[edges[i][1]][edges[i][0]] = true;       
    }
    //判断是否有环，并需要判断是否是一张图,有没有断开的节点
    bool flag = ifGraphTree(n, Graph);
    cout << "flag:" << flag << endl;
    return 0;
}

