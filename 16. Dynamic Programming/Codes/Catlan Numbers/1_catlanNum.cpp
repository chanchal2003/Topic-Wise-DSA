/*
C0 = 1
C1 = 1
C2 = C0*C1 + C1*C0
C3 = C0*C2 + C1*C1 + C2*C0
C4 = C0*C3 + C1*C2 + C2*C1 + C3*C0

if test case of any series is 
1 1 2 5 14 42
 then that number can be solved using catalon
*/


#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    cin>>n;
    vector<int> dp(n+1,0);
    dp[0] = 1, dp[1] = 1;

    for(int i=2; i<n+1; i++){
        for(int j=0; j<i; j++){
            dp[i] += dp[j] * dp[i-j-1];
        }
    }

    for(int i=0; i<=n; i++){
        cout<<dp[i]<<" ";
    }
    cout<<endl;

    return 0;
}