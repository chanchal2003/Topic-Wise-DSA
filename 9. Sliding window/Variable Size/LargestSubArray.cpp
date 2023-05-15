//Given an array containing N integers and an integer K., Your task is to find the length of the longest Sub-Array with the sum of the elements equal to the given value K.

//Input :
/*A[] = {10, 5, 2, 7, 1, 9}
K = 15
Output : 4
Explanation:
The sub-array is {5, 2, 7, 1}.


We will be storing sum and its corresponding index that is
hashmap will look like this
a[0](key) = 0(value)
a[0]+a[1] = 1
a[0]+a[1]+a[2] = 2

now consider a aaray 10,15,-5 and the sum should be 20, 
            a0,a1,....,ak,ak+1,....ak+n
            CurSum array is from a0 to ak+n, here sum array is from ak to ak+1
            and if their differnvce is zero this means that the array starts with
            a0 so its length will be i+1

*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    {
        unordered_map<int,int> mp;
        // int i=0;
        int curSum=0; 
        int maxLen=0;
        for(int i=0; i<N; i++){
            curSum  = curSum + A[i];
            /**/
            if(curSum-K == 0){
                maxLen=max(i+1,maxLen);
            }
            if(mp.find(curSum-K) != mp.end()){
                maxLen = max(maxLen,i-mp[curSum-K]);
            }
            if(mp.find(curSum-K) == mp.end()){
               mp[curSum]=i;
            }
            
        }
        return maxLen;
    }
};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends