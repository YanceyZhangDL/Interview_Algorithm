/****************************************************************
    Copyright (C) 2016 Yancey Zhang. All rights reserved.
					      									  
    > File Name:         < calc_string_distance.cpp >
    > Author:            < Yancey Zhang >
    > Mail:              < yanceyzhang2013@gmail.com >
    > Created Time:      < 2016/07/30 >
    > Last Changed: 
    > Description:
****************************************************************/


#include <iostream>
#include <string>
using namespace std;

/***************************************************************
 * 问题: 求字符串相似度
 * 将两个不同字符串变为相同字符串方法
 * 1. 修改一个字符
 * 2. 增加一个字符
 * 3. 减少一个字符
***************************************************************/

int minValue(int t1, int t2, int t3)
{
	if(t1 > t2)
	{
		return t2 > t3 ? t3 : t2; 
	}
	else
	{
		return t1 > t3 ? t3 : t1; 
	}
}

int CalcStringDistance(string strA, int pABegin, int pAEnd,
		string strB, int pBBegin, int pBEnd)
{
	// 先考虑当其中一个字符串为空的情况
	if(pABegin > pAEnd) 
	{
		if(pBBegin > pBEnd)
			return 0;
		else
			return pBEnd - pBBegin + 1; //加1是防止最后算出的length = 0
	}
	if(pBBegin > pBEnd) 
	{
		if(pABegin > pAEnd)
			return 0;
		else
			return pAEnd - pABegin + 1; 
	}
	if(strA[pABegin] == strB[pBBegin])
	{
		return CalcStringDistance(strA, pABegin + 1, pAEnd, strB, pBBegin + 1, pBEnd);
	}
	else
	{
		int t1 = CalcStringDistance(strA, pABegin, pAEnd, strB, pBBegin + 1, pBEnd);
		int t2 = CalcStringDistance(strA, pABegin + 1, pAEnd, strB, pBBegin, pBEnd);
		int t3 = CalcStringDistance(strA, pABegin + 1, pAEnd, strB, pBBegin + 1, pBEnd);
		return minValue(t1, t2, t3) + 1;
	}
	 
}

int main()
{
	//string strA = "Ajdnk";
	//string strB = "Anh";
	string strA = "Ajdnk";
	string strB = "Ajnnkmoh";
	//cout << sizeof(strA)/sizeof(strA[0]) << endl; // 求数组长度
	//cout << strA.size() << "," << strA.length() << endl; // 求string类型字符床长度
	int length = CalcStringDistance(strA, 0, strA.size() - 1, strB, 0, strB.size() - 1);
	float similarity = 1.0 / length;
	cout << similarity << endl;
	return 0;
}
