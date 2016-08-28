/****************************************************************
    Copyright (C) 2016 Yancey Zhang. All rights reserved.
					      									  
    > File Name:         < find_min_max_num.cpp >
    > Author:            < Yancey Zhang >
    > Mail:              < yanceyzhang2013@gmail.com >
    > Created Time:      < 2016/08/29 >
    > Last Changed: 
    > Description:
****************************************************************/


#include <iostream>
using namespace std;

/****************************************************************
 * 同时选出最大和最小的数
****************************************************************/

// 下面这个算法虽遍历一边，但比较次数是2N
// 最好的方法是数组分成两部分来比较，这样最多复杂度降到1.5N
int find_minmax_num(int *a, int len,int *min, int *max)
{
	if(!a)
		return -1;
	if(len < 2)
	{
		*min = *max = a[0];
		return 0;
	}
	a[0] > a[1]? *min = a[1], *max = a[0]:*min = a[0], *max = a[1];
	for(int i = 2; i < len; i++)
	{
		if(a[i] > *max)
			*max = a[i];
		else if(a[i] < *min)
			*min = a[i];
	}
	return 0;
}

int main()
{
	int len = 10;
	int a[] = {3,2,4,6,7,1,8,4,3,11};
	int min, max;
	find_minmax_num(a, 10, &min, &max);
	cout << min << "," << max << endl;
	return 0;
}
