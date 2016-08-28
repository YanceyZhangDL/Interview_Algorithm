/****************************************************************
    Copyright (C) 2016 Yancey Zhang. All rights reserved.
					      									  
    > File Name:         < recursive_fib.cpp >
    > Author:            < Yancey Zhang >
    > Mail:              < yanceyzhang2013@gmail.com >
    > Created Time:      < 2016/08/28 >
    > Last Changed: 
    > Description:
****************************************************************/


#include <iostream>
using namespace std;

/****************************************************************
 * 计算斐波那契数列
 * f(n) = f(n-1) + f(n-2)
****************************************************************/

const int N = 10;

int fib(int n, int *a)
{
	if(n == 0)
		return 0;
	if(n == 1)
		return 1;
	a[n - 1] = fib(n-1, a) + fib(n-2, a);
	return a[n - 1]; // 数组存的时候是n-1, 这个要特别注意
}

int main()
{
	int a[N];
	memset(a, -1, sizeof(a)/sizeof(int));
	cout << sizeof(a) / sizeof(int) << endl;
	int num = fib(N, a);
	cout << num << endl; 
	return 0;
}
