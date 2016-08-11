/****************************************************************
    Copyright (C) 2016 Yancey Zhang. All rights reserved.
					      									  
    > File Name:         < divisible_number.cpp >
    > Author:            < Yancey Zhang >
    > Mail:              < yanceyzhang2013@gmail.com >
    > Created Time:      < 2016/08/11 >
    > Last Changed: 
    > Description:
****************************************************************/


#include <iostream>
#include <vector>
using namespace std;


/****************************************************************
 * 找出一个数：
 * 第一位可以被1整除
 * 前两位可以被2整除
 * ...
 * 前9位能被9整除
****************************************************************/

bool check[10]; // 检查每一位是否出现，保证9位数每一位不重复
vector<int> v;
void nineBitInteger(int k, long long a)
{
	// 判断是否可以被位数整除(k)整除，不可则结束
	if(k && a % k != 0) return;
	// 第9位也符合条件则将数A保存起来
	if(k == 9)
	{
		v.push_back(a);
		return;
	}
	// 递归过程
	for(int i = 1; i<= 9; i++)
	{
		if(!check[i])
		{
			check[i] = 1;
			nineBitInteger(k + 1, a * 10 + i);
			check[i] = 0;
		}
	}
}
int main()
{
	nineBitInteger(0,0);
	for(int i = 0; i < v.size(); i++)
		cout << v[i] << endl;
	return 0;
}
