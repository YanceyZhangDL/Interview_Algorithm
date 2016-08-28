/****************************************************************
    Copyright (C) 2016 Yancey Zhang. All rights reserved.
					      									  
    > File Name:         < max_k_numbers.cpp >
    > Author:            < Yancey Zhang >
    > Mail:              < yanceyzhang2013@gmail.com >
    > Created Time:      < 2016/08/28 >
    > Last Changed: 
    > Description:
****************************************************************/


#include <iostream>
using namespace std;

/****************************************************************
 * 寻找一个很大的数组中最大的k个数
****************************************************************/

const int k = 10;

// 大小为k的最小堆的维护过程
void find_MaxKNums(int *a, int num)
{
	if(num <= a[0])
		return;
	a[0] = num;
	int p = 0;
	while(p < k)
	{
		int q = 2 * p + 1;// 左孩子
		if(q >= k)
			break;
		if(q + 1 < k && a[q] > a[q + 1]) // 和小的比，若左孩子大于右孩子，则和右孩子比
			q = q + 1;
		if(a[p] > a[q])
		{
			int tmp = a[p];
			a[p] = a[q];
			a[q] = tmp;
			p = q;
		}
		else 
			break;
	}
}

int main()
{

	return 0;
}
