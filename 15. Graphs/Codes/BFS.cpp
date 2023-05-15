/*
When node goes into its bfs it runs on all its degrees that the for loop runs for all degrees of that node for a given node
Total Degree of the graph is equal to 2*Edges
Time Complexity : O(N+2E)
Space Complexity : O(2N)

*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[])
    {
        // Code here
        vector<int> bfs;
        int visited[V] = {0};
        queue<int> q;
        q.push(0);
        bfs.push_back(0);
        visited[0] = 1;

        while (!q.empty())
        {
            int front = q.front();
            q.pop();
            for (auto itr : adj[front])
            {
                if (!visited[itr])
                {
                    visited[itr] = 1;
                    q.push(itr);
                    bfs.push_back(itr);
                }
            }
        }

        return bfs;
    }
};

//{ Driver Code Starts.
int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++)
        {
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