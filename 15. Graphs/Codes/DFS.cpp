/*
Time complexity : O(N + 2E)
Space Complexity :O(N)
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    
    void dfs(int V,vector<int> adj[],int start,int visited[],vector<int> &ans){
        visited[start] = 1;
        ans.push_back(start);
        for(auto itr : adj[start]){
            if(!visited[itr]){
                dfs(V,adj,itr,visited,ans);
            }
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int visited[V] = {0};
        int start = 0;
        vector<int> ans;
        dfs(V,adj,start,visited,ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.dfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
/*
1
5 4
0 2
0 3
0 1
2 4
*/