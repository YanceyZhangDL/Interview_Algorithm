#### 递归（recursion）：程序调用自身的编程技巧。

* 递归满足2个条件：

-- 1）有反复执行的过程（调用自身）

-- 2）有跳出反复执行过程的条件（递归出口）


##### 举例(Hanoi塔)

```
//河内塔
void hanoi(int n,int p1,int p2,int p3)
{
	if(1==n)
		cout<<"盘子从"<<p1<<"移到"<<p3<<endl;
	else
	{
		hanoi(n-1,p1,p3,p2);
		cout<<"盘子从"<<p1<<"移到"<<p3<<endl;
		hanoi(n-1,p2,p1,p3);
	}
}
```