//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
We use for loop when there are more than 1 connected components

Time Complexity : O(N+2E) + O(N)
Space Complexity: O(3*N)
*/

class Solution {
  
  private:
  bool detectCycle(vector<int> adj[],vector<bool> &visited, int start,int parent){
      visited[start] = true;
      for(auto adjNode : adj[start]){
          if(!visited[adjNode]){
              if(detectCycle(adj,visited,adjNode,start)){
                  return true;
              }
          }
          //already visited
          else if(parent != adjNode){
              return true;
          }
      }
      return false;
  }
    
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<bool> visited(V,0);
        for(int i=0; i<V; i++){
            if(!visited[i]){
                if(detectCycle(adj,visited,i,-1)){
                    return true;
                }
            }
        }
        return false;
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
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends