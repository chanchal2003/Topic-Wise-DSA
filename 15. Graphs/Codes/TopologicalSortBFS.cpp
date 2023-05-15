//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
In topological sort if there is a edge between u and v then u appears before v.
1. Why not undirected 
    for undirected if a edge exits between u and v,then edge will be there between v and u
    so we won't be able to arrange it
2. Why not cyclic
    consider you have a cycle from 1->2->3->1
    Now according to topological sort
    1 should appear before 2, and similarly 2 should appear 3, nd 3 should appear before 1
    1 2 3, but third condition won't be satisfied here hence due to cyclic dependency we cannot topologically sort the vertices
    
Hence to satisfy the conditions of topological sort we use directed acyclic graph

It used in the questions where there is dependency of doing some work 
Consider A->B->C 
Consider that You have to complete function C, for this you need to complete A, b first hence we want that TaskA and B to be completed first

Hence we use indegree find, the node whose indegree will be least will be executed first as it is least dependent and as we execute that task first, we will remove all  the dependicies releated to that particular task 

Time Complexity : O(V+2E)
Space Complexity : O(N)

*/

class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
        vector<int> indegree(V,0);
        vector<int> ans;
	    for(int i=0; i<V; i++){
	        for(int adjNode : adj[i]){
	            indegree[adjNode]++;
	        }
	    }
	    
	    queue<int> q;
	    for(int i=0; i<V; i++){
	        if(indegree[i]==0){
	            q.push(i);
	        }
	    }
	    
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        ans.push_back(node);
	        
	        for(int adjNode : adj[node]){
	            indegree[adjNode]--;
	            if(indegree[adjNode]==0){
	                q.push(adjNode);
	            }
	        }
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends