#include<bits/stdc++.h>
using namespace std;

int countSetBits(int num){
    int count = 0;
    while(num > 0){
        count += (num&1);
        num >>= 1;
    }
    return count;
}

int countSetBitsOpti(int n){
    int count = 0;
    while(n != 0){
        int rmsb = n & -n;
        n = n - rmsb;
        count++;
    }
    return count;
}

int main()
{
    int n;
    cin>>n;
    
    //O(k),k is the number of bits
    cout<<(__builtin_popcount(n))<<endl;
    
    //check all 32 bits O(32)
    int resultBrute = countSetBits(n);
    cout<<resultBrute<<endl;
    
    //kernoghan algo->  checks only 1's (checks only one's)
    int resultOpti = countSetBitsOpti(n);
    cout<<resultOpti<<endl;

    return 0;
}
