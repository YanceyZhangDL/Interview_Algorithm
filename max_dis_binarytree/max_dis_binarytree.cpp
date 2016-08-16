/****************************************************************
    Copyright (C) 2016 Yancey Zhang. All rights reserved.
					      									  
    > File Name:         < max_dis_binarytree.cpp >
    > Author:            < Yancey Zhang >
    > Mail:              < yanceyzhang2013@gmail.com >
    > Created Time:      < 2016/08/16 >
    > Last Changed: 
    > Description:
****************************************************************/


#include <iostream>
using namespace std;

/****************************************************************
 * 求一颗二叉树中的节点最大距离
 * 解题思路：
 * 1. 最大距离＝左子树最大距离＋右子树最大距离＋2
 * 2. 最大距离＝单子树最大距离＋1(若没有左子树或右子树)
****************************************************************/
struct node{

	node* pLeft;
	node* pRight;
	int leftMaxDis;  // 左子树最大距离
	int rightMaxDis; // 右子树最大距离
	char chValue;
}; 

int nMaxDis = 0;

// 寻找二叉树最大距离
// 注意返回值为空
void findMaxDis(node* p)
{
	// 遍历到叶子节点，返回
	if(p == NULL)
		return;
	// 如果左子树为空，那么该节点的左边最长距离为0
	if(p -> pLeft == NULL)
	{
		p -> leftMaxDis = 0;
	}
	// 如果右子树为空，那么该节点的右边最长距离为0
	if(p -> pRight == NULL)
	{
		p -> rightMaxDis = 0;
	}
	// 如果左子树不为空，递归寻找左子树最长距离
	if(p -> pLeft != NULL)
	{
		findMaxDis(p -> pLeft);
	}
	// 如果右子树不为空，递归寻找右子树最长距离
	if(p -> pRight != NULL)
	{
		findMaxDis(p -> pRight);
	}
	// 计算左子树最长节点距离
	if(p -> pLeft != NULL)
	{
		int nTempMax = 0;
		if(p->pLeft->leftMaxDis > p->pLeft->rightMaxDis)
			nTempMax = p->pLeft->leftMaxDis;
		else	
			nTempMax = p->pLeft->rightMaxDis;
		p -> leftMaxDis = nTempMax + 1;
	}
	// 计算右子树最长节点距离
	if(p -> pRight != NULL)
	{
		int nTempMax = 0;
		if(p->pRight->leftMaxDis > p->pRight->rightMaxDis)
			nTempMax = p->pRight->leftMaxDis;
		else	
			nTempMax = p->pRight->rightMaxDis;
		p -> rightMaxDis = nTempMax + 1;
	}
	// 更新最长距离
	if(p -> rightMaxDis + p -> leftMaxDis > nMaxDis)
		nMaxDis = p -> rightMaxDis + p -> leftMaxDis; 
}
int main()
{
	return 0;
}
