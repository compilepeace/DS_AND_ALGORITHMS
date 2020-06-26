#include<iostream>
#include <cstring>
using namespace std;

void format(char *a, int i, int n, char *o, int j)
{
	// Base case : If we reach end of string marked by '\0'
	if (i == n)
		return;
	
	// Recursive case (Modification expression for i and j)
	if (a[i] == a[i + 1]){
		o[j++] = a[i++];
		o[j++] = '*';
		o[j] = '\0';
	}
	else{
		o[j++] = a[i++];
		o[j] = '\0';
	}

	format(a, i, n, o, j);
}

/*
void format(char *a, int i, int n, char *o, int j)
{
    if (i == n)
        return;
    
    if (a[i] == a[i + 1]){
        o[j] = a[i];
        o[j+1] = '*';
        o[j + 2] = '\0';
        format(a, i + 1, n, o, j + 2);
    }
    else{
        o[j] = a[i];
        o[j + 1] = '\0';
        format(a, i + 1, n, o, j + 1);
    }

}
*/

int main() {
	char a[10005];
	cin >> a;

	char *o = (char *)malloc(2 * strlen(a) + 1);

	format(a, 0, strlen(a), o, 0);

	cout << o << endl;

	return 0;
}


