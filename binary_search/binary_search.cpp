/****************************************************************
    Copyright (C) 2016 Yancey Zhang. All rights reserved.
					      									  
    > File Name:         < binary_search.cpp >
    > Author:            < Yancey Zhang >
    > Mail:              < yanceyzhang2013@gmail.com >
    > Created Time:      < 2016/08/21 >
    > Last Changed: 
    > Description:
****************************************************************/


#include <iostream>
#include <string.h>
using namespace std;

int binarySearch(int* a, int m, int len)
{
	if(!a)
		return -1;
	int begin = 0;
	int end = len - 1;
	int mid = begin + (end - begin) / 2;
	while(begin < end - 1)
	{
		if(a[mid] == m)
		{
			return mid;
		}
		else if(a[mid] < m)
		{
			begin = mid;
		}
		else
		{
			end = mid;
		}
		mid = begin + (end - begin) / 2;
	}
	if(a[begin] == m)
		return begin;
	if(a[end] == m)
		return end;
	else
		return -1;

}

int main()
{
	int a[] = {1, 2, 3, 4, 6, 7, 11, 19, 21};
	int len = sizeof(a)/sizeof(int);
	int m = 7;
	int num = binarySearch(a, m, len);
	cout << num << endl;
	cout << binarySearch(a, 3, len) << endl;
	cout << binarySearch(a, 11, len) << endl;
	cout << binarySearch(a, 1, len) << endl;
	cout << binarySearch(a, 31, len) << endl;
	cout << binarySearch(a, 21, len) << endl;
	cout << binarySearch(a, -5, len) << endl;
	return 0;
}
