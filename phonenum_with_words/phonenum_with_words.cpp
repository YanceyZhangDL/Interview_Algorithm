/****************************************************************
    Copyright (C) 2016 Yancey Zhang. All rights reserved.
					      									  
    > File Name:         < phonenum_with_words.cpp >
    > Author:            < Yancey Zhang >
    > Mail:              < yanceyzhang2013@gmail.com >
    > Created Time:      < 2016/07/28 >
    > Last Changed: 
    > Description:
****************************************************************/


#include <iostream>
using namespace std;

/****************************************************************
 * 给定手机号，输出所有可能在手机键盘上对应的单词组合
****************************************************************/

int main()
{
	// 数字对应字母索引表
	char c[10][10] = {
		
		"",       // 0
		"",       // 1
		"ABC",    // 2
		"DEF",    // 3
		"GHI",    // 4
		"JKL",    // 5
		"MNO",    // 6
		"PQRS",   // 7
		"TUV",    // 8
		"WXYZ",   // 9
	
	};
	int total[] = {0, 0, 3, 3, 3, 3, 3, 4, 3, 4};
	char number[] = {8,8,7,5,3,7,2,9}; // 存电话号码
	const unsigned int len = strlen(number);
	cout << "len:"<< len << endl;
	char answer[len]; // 存第几位
	memset(answer, 0, len*(sizeof(char))); 

	int m = 0;
	// 非递归方法
	while(true)
	{
		for(int i = 0; i < len; i++)
			cout << c[number[i]][answer[i]];
		cout << endl;
		
		int k = len-1;
		while(k >= 0)
		{
			if(answer[k] < total[number[k]] - 1)
			{
				answer[k]++;
				break;
			}
			else
			{
				answer[k] = 0;
				k--;
			}
		}
		if(k < 0)
			break;

	}

	return 0;
}
