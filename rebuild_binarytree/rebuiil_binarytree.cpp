/****************************************************************
    Copyright (C) 2016 Yancey Zhang. All rights reserved.
					      									  
    > File Name:         < rebuiil_binarytree.cpp >
    > Author:            < Yancey Zhang >
    > Mail:              < yanceyzhang2013@gmail.com >
    > Created Time:      < 2016/08/17 >
    > Last Changed: 
    > Description:
****************************************************************/


#include <iostream>
using namespace std;

/****************************************************************
 * 给定二叉树的前序和中序和中序遍历的结果，重建二叉树
****************************************************************/

// 定义树的长度，为了后序调用实现的简单，直接用宏定义节点的总数
#define TREELEN 6

// 树节点
struct Node
{
	Node* pLeft;
	Node* pRight;
	char chValue; // 节点值
};

void Rebuild(char* pPreOrder, // 前序遍历结果
		     char* pInOrder,  // 中序遍历结果
			 int nTreeLen, // 树长度
			 Node** pRoot) // 根节点
{
	// 检查边界条件
	if(pPreOrder == NULL || pInOrder == NULL)
	{
		return;
	}
	// 获得前序遍历的第一个节点
	Node* pTemp = new Node;
	pTemp -> chValue = *pPreOrder;
	pTemp -> pLeft = NULL;
	pTemp -> pRight = NULL;

	// 如果跟节点为空，把当前节点直接复制到根节点
	if(*pRoot == NULL)
	{
		*pRoot = pTemp;
	}

	// 如果当前树长度为1，那么已经是最后一个节点(终止条件)
	if(nTreeLen == 1)
	{
		return;
	}

	// 寻找子树长度
	char* pOrgInder = pInOrder;
	char* pLeftEnd = pInOrder; // 两个指针做减法得到长度
	int nTempLen = 0;

	// (在中序遍历序列中)找到左子树的结尾
	while(*pPreOrder != *pLeftEnd) // 若前序的跟节点不等于中序的跟节点
	{
		if(pPreOrder == NULL || pLeftEnd == NULL)
			return;

		nTempLen++;

		// 记录临时长度，以免溢出
		if(nTempLen > nTreeLen)
		{
			break;
		}

		pLeftEnd++;
	}

	// 寻找左子树长度
	int nLeftLen = int(pLeftEnd - pOrgInder);
	
	// 寻找左子树长度
	int nRightLen = nTreeLen - nLeftLen - 1;

	// 重建的过程要对照着实际的前序和中序遍历的例子来写，这样写的才会比较顺畅
	// 重建左子树
	if(nLeftLen > 0)
	{
		Rebuild(pPreOrder + 1, pInOrder, nLeftLen, &((*pRoot) -> pLeft));
	}
	// 重建右子树
	if(nRightLen > 0)
	{
		Rebuild(pPreOrder + nLeftLen + 1, pInOrder + nLeftLen + 1, nRightLen, &((*pRoot) -> pRight));
	}
}
int main()
{
	char szPreOrder[TREELEN] = {'a','b','c','d','e','f'};
	char szInOrder[TREELEN] = {'d','b','a','e','c','f'};

	Node* pRoot = NULL;
	Rebuild(szPreOrder, szInOrder, TREELEN, &pRoot);
	return 0;
}
