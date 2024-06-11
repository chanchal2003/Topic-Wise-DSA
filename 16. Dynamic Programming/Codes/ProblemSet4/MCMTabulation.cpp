/*
This is gap method
*/

#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>> dp(N-1,vector<int>(N-1,-1));
        for(int gap=0; gap<dp.size(); gap++){
            for(int i=0, j=gap; j<dp.size();i++,j++ ){
                if(gap==0){
                    dp[i][j] = 0;
                }
                else if(gap==1){
                    dp[i][j] = arr[i]*arr[j]*arr[j+1];
                }
                else{
                    int mini = INT_MAX;
                    for(int k=i; k<=j-1; k++){
                        int left = dp[i][k];
                        int right = dp[k+1][j];
                        int multi = arr[i]*arr[k+1]*arr[j+1];
                        mini = min(left+right+multi,mini);
                    }
                    dp[i][j] = mini;
                }
            }
        }
        return dp[0][dp.size()-1];
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.matrixMultiplication(N, arr) << endl;
    }
    return 0;
}

/*
1
5
40 20 30 10 30
*/ 