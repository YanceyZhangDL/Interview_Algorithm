###使用Memoization，以避免递归重复计算

考虑Fibonacci（斐波那契）问题;

Fibonacci问题是可以通过简单的递归方法来解决：

```
int fib ( n )
 { 
    if ( n == 0 || n == 1 ) { 
        return 1; 
    } 
    else { 
        return fib( n - 2 ) + fib ( n - 1 ); 
    } 
}
```
 注：在这里，我们考虑Fibonacci 系列从1开始，因此，该系列看起来：1，1，2，3，5，8，...


注意：从递归树，我们计算fib（3）函数2次，fib（2）函数3次。这是相同函数的重复计算。

为了避免重复计算，我们使用这个简单的技术叫做Memoization，可以被用在递归，加强计算速度。

fibonacci 函数Memoization的代码，应该是下面的这个样子：

```
int calc_fib ( int n )
 { 
    int val[ n ] , i; 
    for ( i = 0; i <=n; i++ ) { 
        val[ i ] = -1;      // Value of the first n + 1 terms of the fibonacci terms set to -1 
    } 
    val[ 0 ] = 1;   // Value of fib ( 0 ) is set to 1 
    val[ 1 ] = 1;    // Value of fib ( 1 ) is set to 1 
    return fib( n , val ); 
}
 int fib( int n , int* value ) 
{
     if ( value[ n ] != -1 ) { 
        return value[ n ];              // Using memoization 
    } 
    else { 
        value[ n ] = fib( n - 2 , value ) + fib ( n - 1 , value );          // Computing the fibonacci term
     }
     return value[ n ];                // Returning the value 
}
```

上面代码的红色部分，不知道为什么可以那么声明，在标准C和C++中数组都不可以那样声明吧，可能是使用编译器进行了扩展。

下面是我用C++写的：


```
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;

int fib(int n,int val[])
{
    if(val[n]!=-1)
        return val[n];
    else
    {
        val[n]=fib(n-1,val)+fib(n-2,val);
        return val[n];
    }
}
void cal_fib(int n)
{
    int *val=new int[n+1];
    for(int i=0;i<=n;i++)
        val[i]=-1;
    val[0]=0;
    val[1]=1;
    fib(n,val);
    copy(val,val+n+1,ostream_iterator<int>(cout," "));
    cout<<endl;
    delete[] val;

}
int main()
{
    for(int i=3;i<=15;i++)
        cal_fib(i);

}
```