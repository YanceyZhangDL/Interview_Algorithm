/****************************************************************
    Copyright (C) 2016 Yancey Zhang. All rights reserved.
					      									  
    > File Name:         < KaprekarNumber.cpp >
    > Author:            < Yancey Zhang >
    > Mail:              < yanceyzhang2013@gmail.com >
    > Created Time:      < 2016/08/02 >
    > Last Changed: 
    > Description:
****************************************************************/

/*
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    unsigned int N;
    unsigned int a[4];
    while(cin >> N)
    {
        
        if(N > 10000 || N < 0)
            continue;
        
        while(N != 6174)
        {
	    a[0] = N % 10;
	    a[1] = N / 10 % 10;
	    a[2] = N / 100 % 10;
	    a[3] = N / 1000;
        	
	    if(a[0]==a[1] && a[1]==a[2] && a[2]==a[3])
            {	
                cout << "N - N = 0000" << endl;
                //cout << endl;
            	break;
            }
            
            sort(a, a+4);
            int max = a[3]*1000 + a[2]*100 + a[1]*10 + a[0];
            int min = a[0]*1000 + a[1]*100 + a[2]*10 + a[3];
            N = max - min;
            cout << max << " - " << a[0] << a[1] << a[2] << a[3] << " = " << N << endl;
        }
        
    }
    return 0; 
}
*/

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N;
    unsigned int a[4];
    while(cin >> N)
    {
        
        if(N > 10000 || N < 0)
            continue;
        
        a[0] = N % 10;
		a[1] = N / 10 % 10;
		a[2] = N / 100 % 10;
		a[3] = N / 1000;
        while(N != 6174)
        {        	
			if(a[0]==a[1] && a[1]==a[2] && a[2]==a[3])
            {	
                cout << a[0] << a[1] << a[2] << a[3] << " - " ;
				cout << a[0] << a[1] << a[2] << a[3] << " = " << "0000" << endl;
                //cout << endl;
            	break;
            }
            
            sort(a, a+4);
            int max = a[3]*1000 + a[2]*100 + a[1]*10 + a[0];
            int min = a[0]*1000 + a[1]*100 + a[2]*10 + a[3];
            N = max - min;
            cout << max << " - " << a[0] << a[1] << a[2] << a[3] << " = "; 
            a[0] = N % 10;
			a[1] = N / 10 % 10;
			a[2] = N / 100 % 10;
			a[3] = N / 1000;
            cout << a[3] << a[2] << a[1] << a[0] << endl;
            //cout << endl; 
        }
        
    }
    return 0; 
}



