#include <iostream>
using namespace std;


/*
 * Multiplying 'x' by 2^n simply means -> x << n 
 * Dividing    'x' by 2^n simply means -> x >> n;
 * (~0) is -1 ( or 0xffffffff for 32 bit container and 0xffffffffffffffff for 64-bit containers) 
 * 
 * Whenever we need to create a number like -> 0000001111 or 1111110000, use the following
 * 0000001111 = ( (1 << 4) - 1) ---> is of the form ( 2^n - 1) (where n is no. of 1's to be needed)
 * 1111110000 = ( (~0) << 4) or ( -1 << 4 ) ---> shifting all the 1's by 4 places.
 *
 *
 * Funtions implemented - 
 * 
 * __builtin_popcount(n) - To count no. of 1's in binary format of n. (n = n & (n - 1) till n > 0
 * isEven()
 * getBit()
 * setBit()
 * clearBit()
 * updateBit()
 * clearLastIBits()
 * clearRangeIToJ()
*/



// Returns true if n is even
bool isEven(int n)
{
    return (n & 1) ? false: true;
}


// Get the value at ith bit of n
int getBit(int n, int i)
{
    int mask = (1 << i);
    
    if ( (n & mask) > 0)
        return 1;
    else
        return 0;
}


// Set bit at ith position of n to 1
int setBit(int n, int i)
{
    int mask = (1 << i);

    return (n | mask);      // (n | (1 << i))
}


// Clear bit at ith position of n to 0
int clearBit(int n, int i)
{
    int mask = ~( 1 << i );
    
    return (n & mask);      // (n & ~(1 << i))
}


// update bit at ith position in n to 'v'
int updateBit(int n, int i, int v)
{
    // Using either of the property: [0 | v => v] or [ 1 & v => v ]
    
    // make the ith bit 0 to use the property [0 | v => v]
    n = n & (~(1 << i));

    // [0 | v => v]
    return (n | (v << i));
}


int clearLastIBits(int n, int i)
{
    int mask = ( -1 << i);      // Set all 32 bits in mask to 1 except last 'i' bits

    return (n & mask);
}


// Suppose we want to clear out 2nd to 4th bit of 1111111 => 1100011
// We can do this by (1100000 | 0000011), i.e. (mask1 | mask2)
int clearRangeIToJ(int n, int i, int j)
{
    int ones = (~0);
    int mask1 = ( ones << (j + 1) );
    int mask2 = (1 << i) - 1;           // 2 ^ i - 1

    int mask = (mask1 | mask2);

    return n & mask;
}


int main()
{
    int n = 10;
   
    cout << getBit(n, 2) << ": " << getBit(n, 1) << endl;
    cout << setBit(n, 1) << ": " << setBit(n, 2) << endl;
    cout << clearBit(n, 1) << endl;
    cout << updateBit(n, 2, 1) << ": " << updateBit(n, 1, 0) << endl;
    cout << isEven(2) << ": " << isEven(1) << endl;

    cout << clearLastIBits(15 , 1) << ": "
         << clearLastIBits(15, 2) << ": " 
         << clearLastIBits(15, 3) << ": "
         << clearLastIBits(15, 4) << endl;

    cout << clearRangeIToJ(31, 1, 3) << endl;
}

