/****************************************************************
    Copyright (C) 2016 Yancey Zhang. All rights reserved.
					      									  
    > File Name:         < least_abstract.cpp >
    > Author:            < Yancey Zhang >
    > Mail:              < yanceyzhang2013@gmail.com >
    > Created Time:      < 2016/08/09 >
    > Last Changed: 
    > Description:
****************************************************************/

/*求出分词之后的文本包含关键词的最短摘要*/

#include "stdio.h"
#include "string.h"
#include "assert.h"

//是否包含所有摘要
int isMatchAll(const char *str,const char *key,int begin,int end)
{
	int ret =0;
	char hash[255];
	int i =0;
	int lenK = strlen(key);
	memset(hash, 0, sizeof(hash));
	for(i = begin; i <= end; i++)
	{
		hash[str[i]] = 1;
	}
	for(i=0;i<lenK;i++)
	{
		if(hash[key[i]]==0)
			break;	
	}
	if(i == lenK )
		ret =1;
		
	return ret;
}
// 查找包含所有关键词的最短长度
void find(const char *str,const char *key)
{

	int lenS = strlen(str);
	int lenK = strlen(key);
	
	int begin = 0;
	int end = 0;
	int minLength = 0x7FFFFFFF;
	int mstart = 0;
	int mend = 0;
	assert(str && key);
	for(;;)
	{
		while(!isMatchAll(str,key,begin,end) && end<lenS)
		{
			end++;		
		}
		while(isMatchAll(str,key,begin,end))
		{
			if(end-begin+1 < minLength)
			{
				minLength = end-begin+1;
				mstart = begin;
				mend = end;
			}
			begin++;
		}
		if(end >= lenS)
			break;
	}
	printf("%d\n", minLength);
	for(; mstart <= mend; mstart++)
		printf("%c", str[mstart]);
}


int main()
{
	char str[] = {'w','o','m','m',
		          'q','p','r','m',
				  'a','s','w','q',
				  'w','m'};

	char key[] = {'q','m'};
	
	//gets(str);
	//gets(key);
	find(str,key);
	return 0;

}
