#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    bitset<32> binaryRepn(n);
    cout<<binaryRepn<<endl;
    // (-n) is complement
    int rmsb = n & -n;
    bitset<32> binaryRepb(rmsb);
    cout<<binaryRepb<<endl; 

    return 0;
}