/****************************************************************
    Copyright (C) 2017 Yancey Zhang. All rights reserved.
					      									  
    > File Name:         < Queen.cpp >
    > Author:            < Yancey Zhang >
    > Mail:              < yanceyzhang2013@gmail.com >
    > Created Time:      < 2017/03/14 >
    > Last Changed: 
    > Description:
****************************************************************/


#include <iostream>
#include <vector>
using namespace std;

// 原始未优化解法
// 8皇后问题，遍历每行的每个点
// 遍历到每个点的时候，判断当前点与之前所有点的关系是否符合要求
int N = 8; //N皇后问题
int count = 0;//符合条件的排列数 

void DFS(vector<int> &chess, int row)
{
    if(row >= N)
    {
        count++;
        for(int i = 0; i < N; i++)
            cout << chess[i];
        cout << endl;
    }
    else 
        for(int i = 0; i < N; i++)
        {
            chess[row] = i; 
            bool flag = true;
            // 判断当前的数是否符合要求
            for(int j = 0; j < row; j++)
            {
                if(chess[row] == chess[j] || abs(chess[row] - chess[j]) == abs(row - j))
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                //cout << i << " " << chess[i] << endl;
                DFS(chess, row + 1);
            }
        }
}

int main()
{
    vector<int> chess(N, 0);
    DFS(chess, 0);
    cout << "符合要求的排列数：" << count << endl;
    return 0;
}
