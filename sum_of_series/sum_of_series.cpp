#include <iostream>
#include <cmath>
using namespace std;

void sumofshulie(float n, int m, float *sum)
{
    if(n < 0 || m <= 0)
          return ;
    if(m == 0)
          return ;
    sumofshulie(sqrt(n), m-1, sum);
    *sum += n;  
    return ;  
}

int main()
{
    float sum = 0;
    float n = 0; 
    int m = 0;
    while(cin >> n >> m)
    {
    	sum = 0;
	sumofshulie(n, m, &sum);
    	cout << int(sum*100)/100.0 << endl;  
    }
	return 0;
}
