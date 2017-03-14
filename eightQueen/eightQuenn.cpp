/****************************************************************
    Copyright (C) 2017 Yancey Zhang. All rights reserved.
					      									  
    > File Name:         < eightQuenn.cpp >
    > Author:            < Yancey Zhang >
    > Mail:              < yanceyzhang2013@gmail.com >
    > Created Time:      < 2017/03/13 >
    > Last Changed: 
    > Description:
****************************************************************/


#include <iostream>
#include <vector>
#include <string.h>
#include <cmath>
using namespace std;

//八皇后问题，按照行进行深度优先搜索
//可以用递归来解决

// 这个版本有问题，暂时没找到问题出在哪???
// 貌似是无法遍历到每个点？？
// 还是状态值的加减有问题？？
int count = 0;

void DFS(vector<int> &chess, int row)
{
    if(row > 7)
    {
        for(int i = 0; i < 8; i++)
            cout << chess[i];
        cout << endl;
        count++;
        return;
    }
    while(chess[row] < 8)
    {
        // 当前点和前面所有点进行比较
        int i = 0; // 初始化为0没法比了
        while(i < row)
        {

            while(chess[row] == chess[i] || (abs)(row - i) == (abs)(chess[row] - chess[i]))
            {
                chess[row]++;
                if(chess[row] > 7)
                {
                    chess[row]=0;
                    return;
                }
            }
            i++;
        }
        DFS(chess, row + 1);
        chess[row]++;
    }
}

int main()
{
    vector<int> chess(8, 0);
    DFS(chess, 0);
    cout << "有效的排列数目为："<< count << endl;
    /*
    for(int i = 0; i < 8; i++)
    {
       cout << chess[i] << " ";
    }
    cout << endl;
    */
    return 0;
}


