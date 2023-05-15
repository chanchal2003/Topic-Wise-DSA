/*
https://takeuforward.org/data-structure/print-longest-common-subsequence-dp-26/
*/

#include <bits/stdc++.h>
using namespace std;

int longestCommonSubsequence(string text1, string text2,vector<vector<int>> &dp)
{
    int n = text1.size();
    int m = text2.size();

    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][m];
}

void printLCS(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    int lengthOflcs = longestCommonSubsequence(s1, s2, dp);
    string ans(lengthOflcs,'$');
    int i = s1.size();
    int j = s2.size();
    int index = lengthOflcs-1;

    while(i>0 && j>0){
        if(s1[i-1] == s2[j-1]){
            ans[index] = s1[i-1];
            i--;
            j--;
            index--;
        }
        else{
            if(dp[i][j-1] > dp[i-1][j]){
                j--;
            }
            else{
                i--;
            }
        }
    }
    
    cout<<ans<<endl;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    printLCS(s1, s2);
    return 0;
}