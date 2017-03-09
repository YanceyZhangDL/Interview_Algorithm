/****************************************************************
    Copyright (C) 2017 Yancey Zhang. All rights reserved.
					      									  
    > File Name:         < XIncludeO.cpp >
    > Author:            < Yancey Zhang >
    > Mail:              < yanceyzhang2013@gmail.com >
    > Created Time:      < 2017/03/09 >
    > Last Changed: 
    > Description:
****************************************************************/


#include <iostream>
#include <vector>
using namespace std;

// 给一个二维矩阵，包含X和O, 找出所有被X围绕的区域，并用X填满
// Insight:好像类似于图像搜索中的找轮廓
// 可以用图搜索的方法来做
// 先考虑边界条件，先考虑四个边上的O，与这四个边上的O相连的所有O都无法被填，置false
// 所以要单独开一个和输入一样大小的二维矩阵来记录点能否被覆盖
// 还要单独开一个图来表示点是否被访问过，用于深度优先搜索 

void DFS(int rowi, int colj, vector<vector<char> > &board, 
        vector<vector<bool> > &NoSrd, vector<vector<bool> > &visited)
{   
    
    int row = board.size(); // 行数
    int col = board[0].size(); // 列数
    // 搜索左边的点
    if(colj-1 > 0 && board[rowi][colj - 1] == 'O' && !visited[rowi][colj - 1])
    { 
        NoSrd[rowi][colj - 1] = true;
        visited[rowi][colj - 1] = true;
        DFS(rowi, colj-1, board, NoSrd, visited);
    }
    // 搜索上边的点
    // 不要加else, 深度优先回退的时候有些节点就遍历不到了
    if(rowi-1 > 0 && board[rowi - 1][colj] == 'O' && !visited[rowi - 1][colj])
    { 
        NoSrd[rowi - 1][colj] = true;
        visited[rowi - 1][colj] = true;
        DFS(rowi-1, colj, board, NoSrd, visited);
    }
    // 搜索右边的点
    if(colj+1 < col  && board[rowi][colj + 1] == 'O' && !visited[rowi][colj + 1])
    { 
        NoSrd[rowi][colj + 1] = true;
        visited[rowi][colj + 1] = true;
        DFS(rowi, colj+1, board, NoSrd, visited);
    }
    // 搜索下边的点
    if(rowi+1 < row  && board[rowi + 1][colj] == 'O' && !visited[rowi + 1][colj])
    { 
        NoSrd[rowi + 1][colj] = true;
        visited[rowi + 1][colj] = true;
        DFS(rowi+1, colj, board, NoSrd, visited);
    }

}
void surroundedRegions(vector<vector<char> >& board) {
    
    int row, col;
    // 先判断边界条件
    // 少于两行两列是不行的
    // XXXXOX
    // XOOOOX
    row = board.size();
    if(row <= 2)
        return; 
    col = board[0].size();
    if(col <= 2)
        return;
    // 从左上角开始搜索
    // 只搜索四个边
    // 标识特定位置的O能否被包围
    vector<vector<bool> > NoSrd(row, vector<bool>(col, false));
    NoSrd[0][0] = true;
    NoSrd[0][col - 1] = true;
    NoSrd[row - 1][0] = true;
    NoSrd[row - 1][col - 1] = true;
    // 标识特定位置的O点能否被访问过
    vector<vector<bool> > visited(row, vector<bool>(col, false));
    // 四个角上的O点貌似不要考虑，直接可以忽略掉
    // 搜索第一列
    for(int i = 1; i < row-1; i++)
    {
        if(board[i][0] == 'O')
        {
            visited[i][0] = true;
            DFS(i, 0, board, NoSrd, visited);
        }
    }
    // 搜索第一行
    for(int j = 1; j < col-1; j++)
    {
        if(board[0][j] == 'O')
        {
            visited[0][j] = true;
            DFS(0, j, board, NoSrd, visited);
        }
    }
    // 搜索最后一列
    for(int i = 1; i < row-1; i++)
    {
        if(board[i][col - 1] == 'O')
        {
            visited[i][col - 1] = true;
            DFS(i, col-1, board, NoSrd, visited);
        }
    }
    // 搜索最后一行
    for(int j = 1; j < col-1; j++)
    {
        if(board[row - 1][j] == 'O')
        {
            visited[j][row - 1] = true;
            DFS(j, row - 1, board, NoSrd, visited);
        }
    }
    // 填满包围的区域
    for(int i = 1; i < row-1; i++)
        for(int j = 1; j < col-1; j++)
        {
            if(board[i][j] == 'O' && NoSrd[i][j] == false)
                board[i][j] = 'X';
        }
        
}
int main()
{
    int row, col;
    cin >> row >> col;
    vector<vector<char> > board(row, vector<char>(col));
    // 读取二维矩阵
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cin >> board[i][j];
        }
    }
    surroundedRegions(board);
    // 打印填满后的二维矩阵
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
