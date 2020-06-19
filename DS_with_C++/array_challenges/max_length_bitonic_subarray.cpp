#include<iostream>
#include <climits>
using namespace std;


int maxLengthBitonicSubarray(int a[], int n)
{
    int result = 1;
    int ilsf = 1, dlsf = 1;             /* increasing/decreasing length so far */

    for (int i = 1; i < n; ++i){
       
       if (a[i] > a[i - 1]){
            ++ilsf;
            result = max(ilsf, result);
            dlsf = 1;
       }
       else{
           ++dlsf;
           result = max(dlsf, result);
           ilsf = 1;
       }
     }

    return result;
}


int main() 
{

	int t, n;

	cin >> t;

	for (int j = 0; j < t; ++j){
		int result = 0;

        cin >> n;
		int a[n];
		
		// Take input in a[]
		for (int i = 0; i < n; ++i)
			cin >> a[i];
	    
        result = maxLengthBitonicSubarray(a, n);
        
		cout << result << endl;
	}
	

	return 0;
}
