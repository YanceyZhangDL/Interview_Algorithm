/****************************************************************
    Copyright (C) 2016 Yancey Zhang. All rights reserved.
					      									  
    > File Name:         < link_list_intersect.cpp >
    > Author:            < Yancey Zhang >
    > Mail:              < yanceyzhang2013@gmail.com >
    > Created Time:      < 2016/08/11 >
    > Last Changed: 
    > Description:
****************************************************************/


#include <iostream>
using namespace std;

struct node{
	node* pNext;
	int data;
};

node * findNode(node *head1, node *head2)
{
	if(head1 == NULL || head2 == NULL)
	{
		return NULL; //若有空链表，肯定不相交
	}
	node *p1, *p2;
	p1 = head1;
	p2 = head2;
	int len1 = 0;
	int len2 = 0;
	int diff = 0; //若相交，求出比较长的链表,
	              //向后移len2-len1位
	while(p1 -> pNext != NULL)
	{
		p1 = p1 -> pNext;
		len1++;
	}
	while(p2 -> pNext != NULL)
	{
		p2 = p2 -> pNext;
		len2++;
	}
	if(p1 != p2) //若最后一个节点不为空，返回NULL
	{
		return NULL;
	}
	diff = abs(len1 - len2);
	if(len1 > len2)
	{
		p1 = head1;
		p2 = head2;
	}
	else 
	{
		p1 = head2;
		p2 = head1;
	}
	for(int i = 0; i < diff; i++)
	{
		p1 = p1 -> pNext;
	}
	while(p1 != p2)
	{
		p1 = p1 -> pNext;
		p2 = p2 -> pNext;
	}
	return p1;
}
int main()
{
	return 0;	
}
