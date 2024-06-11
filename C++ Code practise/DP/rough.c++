#include<bits/stdc++.h>
using namespace std;

int getLengthOfLCS(string & str1, string & str2) {
    int str1Len = str1.size();
    int str2Len = str2.size();
    vector<vector<int>> dp(str1Len+1,vector<int>(str2Len+1,-1));
    for(int i=0; i<=str1Len; i++){
        for(int j=0; j<=str2Len; j++){
            if(i==0 or j==0){
                dp[i][j]=0;
            }
        }
    }
    for(int i=1; i<=str1Len; i++){
        for(int j=1; j<=str2Len; j++){
            if(str1[i-1]==str2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }
    return dp[str1Len][str2Len];
}

int longestPalindromeSubsequence(string s)
{
    // Write your code here.
    string reversed = s;
    reverse(reversed.begin(),reversed.end());
    return getLengthOfLCS(s,reversed);
}

int main(){
    cout<<"Take input string"<<endl;
    string s;
    getline(cin,s);
    cout<<longestPalindromeSubsequence(s)<<endl;
    return 0;
}