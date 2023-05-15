//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
0 -> 1 -> 2
       -> 4
Now 2 and 4 come from 1 , that is 2 and 4 have only one parent whereas 3 has 2 parents
hence if 2 is able to reach 3 through some ptha and even 4 is able to reach 3,
this means that cycle exits

0 is 1's parent, hence we check that if a node is already visited and is not equal to parent
then cycle exits in graph
*/

/*
Time Complexity : O(N + 2E) for every node we traversing all its nodes and hence it is 2E

*/

class Solution {
    
  private:

  bool detectCycle(int i, vector<int> adj[], vector<bool> &visited){
      visited[i] = true;
      queue<pair<int,int>> q;
      q.push({i,-1});
      
      while(!q.empty()){
          int node = q.front().first;
          int parent = q.front().second;
          q.pop();
          
          for(auto adjNode : adj[node]){
              if(!visited[adjNode]){
                  q.push({adjNode,node});
                  visited[adjNode] = true;
              }
              else if(parent != adjNode){
                  return true;
              }
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
                if(detectCycle(i,adj,visited)){
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

/*
INput
5 5
0 1
1 2
1 4
2 3
3 4
*/