#include <iostream>
using namespace std;


// Print 2D array in spiral form
void spiralPrint(int a[][1000], int n, int m)
{
	int sr = 0;			// start row
	int sc = 0;			// start col
	int er = n - 1;		// end row
	int ec = m - 1;		// end col

	while ( sr <= er and sc <= ec ) 
	{
		// row ->
		for (int j = sc; j <= ec; ++j)
			cout << a[sr][j] << " ";
		++sr;

		// col down
		for (int i = sr; i <= er; ++i)
			cout << a[i][ec] << " ";
		--ec;

		// row <-
		if (er > sr)
		{
			for (int j = ec; j >= sc; --j)
				cout << a[er][j] << " ";
			--er;
		}

		// col up
		if (ec > sc)
		{
			for (int i = er; i >= sr; --i)
				cout << a[i][sc] << " ";
			++sc;
		}
	}

	cout << endl;
}


int main()
{
	int n, m;
	int a[1000][1000];

	cin >> n >> m;
	cout << endl;
	
	int val = 1;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j){
			a[i][j] = val;
			cout << a[i][j] << "\t";
			++val;
		}
		cout << endl;
	}

	cout << endl;

	spiralPrint(a, n, m);

}
