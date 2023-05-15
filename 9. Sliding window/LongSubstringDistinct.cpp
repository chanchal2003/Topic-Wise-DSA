//{ Driver Code Starts
//Given a string S, find length of the longest substring with all distinct characters. 
//Input:
// S = "geeksforgeeks"
// Output: 7
// Explanation: "eksforg" is the longest 
// substring with all distinct characters

#include<bits/stdc++.h>
using namespace std;
int longestSubstrDistinctChars (string S);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;

        cout << longestSubstrDistinctChars (S) << endl;
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends


int longestSubstrDistinctChars (string S)
{
    // your code here
    int i=0,j=0;
        int n = S.length();
        int maxLen = 0;
        unordered_map<int,int> mp;
        while(j<n){
            mp[S[j]]++;
            //When there will be distinct charachters in th strings then size of the map will be equal to (j-i+1)
            if(mp.size()==j-i+1){
                maxLen = max(maxLen,j-i+1);
            }
            else if(mp.size() < j-i+1){
                while(mp.size() < j-i+1){
                    mp[S[i]]--;
                    if(mp[S[i]]==0){
                        mp.erase(S[i]);
                    }
                    i++;
                }
            }
            j++;
        }
        return maxLen;
    }
