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

DFS goes this last node that is the most dependent node and stores that node in stack and then it comes up till it reaches independent node
*/

class Solution
{
    private:
    void dfs(int node, vector<bool> &visited,vector<int> adj[],stack<int> &st){
        visited[node] = true;
        for(auto adjNode : adj[node]){
            if(!visited[adjNode]){
                dfs(adjNode,visited,adj,st);
            }
        }
        st.push(node);
    }
    
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    vector<int> ans;
	    stack<int> st;
	    vector<bool> visited(V,0);
	    
	    for(int i=0; i<V; i++){
	        if(!visited[i]){
	            dfs(i,visited,adj,st);
	        }
	    }
	    
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
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

/*
1
3 4
3 0
1 0
2 0
*/

/*
here A is dependent on D, B is on D,C is on D
So if we want our work to be completed then we need to complete the independent work first and then least dependent and then in this way we may comple;ete our whole task
hence we need to find the dependencies and complete the work

Hence we go till depth, at the last node in the tree we find a node that is least dependent hence we will complete our work andstore that nodein stack
in this way we when we return from the last node we store nodes in stack with a intution that all the nodes that have been below its tree have completed their execution

*/