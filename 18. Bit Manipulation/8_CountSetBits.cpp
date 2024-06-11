/*
https://www.youtube.com/watch?v=g6OxU-hRGtY&ab_channel=Pepcoding
count set bits in first N natural numbers
Steps:
1. Largest power of 2 less than eqaual to 11
2. if you write properly you'll understand 
*/

#include<bits/stdc++.h>
using namespace std;

int largestPowerOf2(int n){
    //bit is the iteration here
    int bit = 0;
    while((1<<bit)<=n){
        bit++;
    } 
    return bit-1;
}

int CountSetBits(int n){
    
}

int main(){
    int n;
    cin>>n;
    cout<<largestPowerOf2(n)<<endl;
    return 0;
}