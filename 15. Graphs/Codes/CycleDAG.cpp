//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

/*
Using topoSort we moved sequentailly and hence the number of steps were minimised

Finding the shortest path to a vertex is easy if you already know the shortest paths to all the vertices that can precede it. Finding the longest path to a vertex in DAG is easy if you already 10 know the longest path to all the vertices that can precede it.
Processing the vertices in topological order ensures that by the time you get to a vertex, you've
already processed all the vertices that can precede it.
Dijkstra's algorithm is necessary for graphs that can contain cycles, because they can't be

topologically sorted.
*/
class Solution {
  public:
  
     void dfs(int node,vector<bool> &visited,vector<pair<int,int>> adjList[],stack<int> &st){
         visited[node] = true;
         for(auto itr : adjList[node]){
             int v = itr.first;
             if(!visited[v]){
                 dfs(v,visited,adjList,st);
             }
         }
         st.push(node);
     }     
     
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
         
        // code here
        
        vector<pair<int,int>> adjList[N];
        for(int i=0; i<M; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adjList[u].push_back({v,wt});
        }
        
        vector<bool> visited(N,0);
        stack<int> st;
        for(int i=0; i<N; i++){
            if(!visited[i]){
                dfs(i,visited,adjList,st);
            }
        }
        
        //find ditance
        vector<int> distance(N,1e9);
        distance[0] = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            for(auto itr : adjList[node]){
                int v = itr.first;
                int wt = itr.second;
                
                if(distance[node]+wt < distance[v]){
                    distance[v] = distance[node]+wt;
                }
            }
        }
        
        for(int i=0; i<N; i++){
            if(distance[i]==1e9){
                distance[i] = -1;
            }
        }
        
        return distance;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends