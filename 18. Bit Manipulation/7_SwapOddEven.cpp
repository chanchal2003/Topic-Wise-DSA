/*
0x -> the complier understands that you are giving a binary number
A in hexadecimal is 1010
5 in hexadecimal is 0101

*/


#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    // cout<<n<<endl;
    bitset<32> binaryN(n);
    cout<<binaryN<<endl;
    int oddMask = 0xAAAAAAAA;
    int evenMask = 0x55555555;

    int odds = (n & oddMask);
    int evens = (n & evenMask);

    odds <<= 1;
    evens >>= 1;

    n = odds | evens;
    bitset<32> binaryNShifted(n);
    cout<<binaryNShifted<<endl;
    return 0;
}