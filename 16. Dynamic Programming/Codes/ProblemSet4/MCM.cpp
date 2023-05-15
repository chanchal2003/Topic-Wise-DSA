//{ Driver Code Starts
// Initial Template for C++

/*
Consider that there are n numbers in the array. Then thhere will be n-1 matrices

40 20 30 10 30
M1 -> 40*20
M2 -> 20*30
M3 -> 30*10
M4 -> 10*30

We have to minimise cost of multiplication
(M1)(M2*M3*M4)
(M1*M2)(M3*M4)
(M1*M2*M3)(M4)

Ans will be min all above three operations
Mi = arr(i-1) + arr(i)

for this
(M1)(M2*M3*M4) k will be at first and we will find cost from i=k, j will start from m2

As to calculate cost of mi we do i-1 hence we will start from i from 1
Now M2*M3*M4 will return some value and M1 will return some value

Consider you have an array
3 5 4 2 1
(M1*M2)(M3*M4) -> M12 * M34 -> M(ANS)
3*5*4 -> 60
4*2*1 -> 8

Dimensions for M12 -> 3*4
Dimensions for M34 -> 4*1

M(Ans) -> 3*4*1 -> 12

60+8+12 -> 80
Total cost

hence formula for total cost will be costOfMatrix(M1*M2)+costOfMatrix(M*M4) + arr[i-1]*arr[k]*arr[j]

40 20 30 10 30
for this test case hence k will be from k->i to j-1 
k=1 -> (1,1) (2,4) -> (M1)(M2*M3*M4)
k=2 -> (1,2) (3,4) -> (M1*M2)(M3*M4)
k=3 -> (1,3) (4,4) -> (M1*M2*M3)(M4)

We need to take best out of them


*/

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

/*
https://www.scaler.com/topics/matrix-chain-multiplication/

change in i nd j
if we initialise out the function call it will update the value of the subproblem not the main
*/

class Solution
{
public:
    
    int costOfMultiplication(int arr[], int i, int j,vector<vector<int>> &dp)
    {
        if (i >= j)
        {
            return 0;
        }

        int minCost = INT_MAX;
        if(dp[i][j] != -1){
            return dp[i][j];
        }

         //why do we initialise this here verytime 
        for (int k = i; k < j; k++)
        {
            int cost = costOfMultiplication(arr, i, k, dp) + costOfMultiplication(arr, k + 1, j, dp) + arr[i - 1] * arr[k] * arr[j];
            minCost = min(minCost, cost);
        }
        return dp[i][j] = minCost;
    }

    int matrixMultiplication(int N, int arr[])
    {
        // code here
        vector<vector<int>> dp(N+1,vector<int>(N+1,-1));
        return costOfMultiplication(arr,1,N-1,dp);
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
// } Driver Code Ends

/*
1
5
40 20 30 10 30
*/ 