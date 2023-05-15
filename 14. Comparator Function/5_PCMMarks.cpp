//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
    public:
    
    class marks{
        public :
        int physics;
        int chemistry;
        int maths;
        
        marks(){
            
        }
        
        marks(int physics,int chemistry,int maths){
            this->physics = physics;
            this->chemistry = chemistry;
            this->maths = maths;
        }
    };
    
    static bool cmp(marks &a,marks &b){
        if(a.physics != b.physics){
            return a.physics < b.physics;
        }
        else if(a.chemistry != b.chemistry){
            return a.chemistry > b.chemistry;
        }
        else{
            return a.maths < b.maths;
        }
    }
    
    
    void customSort (int phy[], int chem[], int math[], int N)
    {
    //     // your code here
        vector<marks> v(N);
        for(int i=0; i<N; i++){
            marks m(phy[i],chem[i],math[i]);
            v[i] = m;
        }
        sort(v.begin(),v.end(),cmp);
        for(int i=0; i<N; i++){
            phy[i] = v[i].physics;
            chem[i] = v[i].chemistry;
            math[i] = v[i].maths;
        }
    } 
};

//{ Driver Code Starts.

int main () 
{
    int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		int phy[n];
		int chem[n];
		int math[n];
		for (int i = 0; i < n; ++i)
			cin >> phy[i] >> chem[i] >> math[i];
        Solution ob;
		ob.customSort (phy, chem, math, n);
		for (int i = 0; i < n; ++i)
			cout << phy[i] << " " << chem[i] << " " << math[i] << endl; 
	}
}

// Contributed By: Pranay Bansal

// } Driver Code Ends

/*
Input:
N = 10
phy[] = {4 1 10 4 4 4 1 10 1 10}
chem[] = {5 2 9 6 3 10 2 9 14 10}
math[] = {12 3 6 5 2 10 16 32 10 4}
Output:
1 14 10
1 2 3
1 2 16
4 10 10
4 6 5
4 5 12
4 3 2
10 10 4
10 9 6
10 9 32
*/