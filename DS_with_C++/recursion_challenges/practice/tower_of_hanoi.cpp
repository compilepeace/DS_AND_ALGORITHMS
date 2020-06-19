#include <iostream>
using namespace std;


// Assuming that we shifted the first top (n-1) disks from A -> B
// then we put the nth disk from A -> C
// then we put the (n-1) disks back from B -> C
void move(int n, char src, char helper, char dest)
{
    // Base case: return if there are no disks to shift
    if (n == 0)
        return;
    
    move( n - 1, src, dest, helper);        // move (n-1) disks from src to helper
    cout << "Move " << n << "th disk from: "
         << src << " -> " << dest << endl;
    move( n - 1, helper, src, dest);        // move (n-1) disks from helper to dest    
}

int main()
{
    int n;
    cin >> n;

    move(n, 'A', 'B', 'C');
}
