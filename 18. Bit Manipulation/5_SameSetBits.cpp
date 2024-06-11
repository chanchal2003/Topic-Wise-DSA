// Given a positive integer N, find out how many positive integers strictly less than N have the same number of set bits as N.

/*
Consider 12 it binary representation is 1100
we have to form all the numbers that consists same number of set bits as 12 but less than it
then i

toh the number can either start with 1 or 0
if the number starts with 1 then remaining is three places and we place 1 one in these three places that is in 3C1 way

*/

#include <bits/stdc++.h>
using namespace std;

/*
here the number is represented using 32 bit format humein bsaicalling bits ko eliminate karna hai isliye hum
*/

int fact(int n)
{
    if (n == 0)
        return 1;
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}

int nCr(int n, int r)
{
    return fact(n) / (fact(r) * fact(n - r));
}

int sameSetBits(int n, int numOfSetBits, int bit)
{
    if(bit==0){
        return 0;
    }
    int mask = 1 << bit;
    int res = 0;
    if ((n & mask) == 0)
    {
        res = sameSetBits(n, numOfSetBits, bit - 1);
    }
    else
    {                                                         // condition is when we get set bit
        int res1 = sameSetBits(n, numOfSetBits - 1, bit - 1); // condition when our answer will start with 1
        int res2 = nCr(bit, numOfSetBits);                    // answer will start with zero
        res = res1 + res2;
    }
    return res;
}

int csb(int n)
{
    int res = 0;
    while (n > 0)
    {
        int rmsb = n & -n;
        n -= rmsb;
        res++;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    int numOfSetBits = csb(n);
    ;
    cout << sameSetBits(n, numOfSetBits, 31);
    return 0;
}