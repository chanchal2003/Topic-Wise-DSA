//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        int sizeOfP = p.size();
        int sizeOfS = s.size();
        unordered_map<char,int> mp;
        for(int k=0; k<sizeOfS; k++){
            mp[s[k]]++;
        }
        int count=mp.size();
        int j=0, i=0;
        while(j < sizeOfS){
            if(mp.find(s[j])!=mp.end()){
                mp[s[j]]--;
                if(mp[s[j]]==0){
                    count--;
                }
            }
                /*we are not earsing that element from the array from we get and idea about the extra charschters present in the map*/
                /*we want to eliminate extra variable this will be done by incrementing a[i]*/
            else if(count==0){
                minLen=min(minLen,j-i+1);
            }
                while(mp[s[i]]<0){
                    i++;
                }
            j++;
        }
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends