//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
ElogE
*/
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<pair<int,int>> v;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        //{dist,{node,parent}}
        pq.push({0,{0,-1}});
        vector<bool> visited(V,0);
        int sum = 0;

        while(!pq.empty()){
            int distance = pq.top().first;
            int node = pq.top().second.first;
            int parent = pq.top().second.second;
            pq.pop();

            if(visited[node]==true){
                continue;
            }

            v.push_back({node,parent});
            visited[node] = 1;
            sum += distance;

            for(auto itr : adj[node]){
                int adjNode = itr[0];
                int edgeWt = itr[1];
                if(!visited[adjNode]){
                    pq.push({edgeWt,{adjNode,node}});
                }
            }
        }
        
        // v.pop_front();
        cout<<"The node in MST are"<<endl;
        v.erase(v.begin());
        for(auto itr : v){
            cout<<itr.first<<" "<<itr.second<<endl;
        }
        cout<<"The sum is"<<endl;
        return sum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

/*
1
3 3
0 1 5
1 2 3
0 2 1
*/
// } Driver Code Ends