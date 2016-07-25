/****************************************************************
    Copyright (C) 2016 Yancey Zhang. All rights reserved.
					      									  
    > File Name:         < string_shift.cpp >
    > Author:            < Yancey Zhang >
    > Mail:              < yanceyzhang2013@gmail.com >
    > Created Time:      < 2016/07/25 >
    > Last Changed: 
    > Description:
****************************************************************/


#include <iostream>
#include <string>
using namespace std;

/***************************************************************
 * 问题描述：字符串移位包含
 * 给定两个字符串s1和s2,判断s2是否能被s1循环移位得到的字符串包含
 *
 * *************************************************************/

int main()
{
	char src[] = "AABBCD";
	char dst[] = "CDAA";

	/*
	// 第一种解法：循环移位，利用字符串比较函数
	int len = strlen(src);
	for(int i = 0; i < len; i++)
	{
		char tmpchar = src[0];
		for(int j = 0; j < len-1; j++)
		{
			src[j] = src[j + 1];
		}
		src[len - 1] = tmpchar; // 这句一定别漏了
		if(strstr(src, dst) != NULL)// strstr(src, dst)若src包含dst, 返回匹配第一个位置，否则返回NULL
		{
			cout << "YES!" << endl;
			return true;
		}
	}
	
	cout << "NO!" << endl;
	return false;
	*/

	// 第二种解法：
	// s1包含s2, 则s2为s1s1的子字符串
	strcat(src,src); //str(src, dst)函数将链接的结果放在src中
	if(strstr(src, dst) != NULL)
	{
		cout << "OK!" << endl;
		return true;
	}
	cout << "NO!" << endl;
	return false;

}
