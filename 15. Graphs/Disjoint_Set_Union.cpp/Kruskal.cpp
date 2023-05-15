/*
vector<vector<int>> adj[]
this will mean that at adj[i], here i is u, we will have a vector stored which will consists of v and weight
TC : O(n+e) + O(nlogn)
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
ElogE
*/

class DisjointSet{
    vector<int> parent,rank;

    public:
    DisjointSet(int n){
        parent.resize(n+1,0);
        rank.resize(n+1,0);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
    }

    int findParent(int u){
        if(parent[u]==u){
            return u;
        }
        return parent[u] = findParent(parent[u]);
    }

    void unionByRank(int u,int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        
        if(ulp_u == ulp_v){
            return;
        }
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_u] > rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else{ //rank of both is same 
            parent[ulp_v] = ulp_u; 
            rank[ulp_u]++; 
        }
    }
};


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<pair<int,pair<int,int>>> edges;
        for(int i=0; i<V; i++){
            for(vector<int> temp : adj[i]){
                int node = i;
                int adjNode = temp[0];
                int weigth = temp[1];
                edges.push_back({weigth,{node,adjNode}});
            }
        }

        sort(edges.begin(),edges.end());

        DisjointSet ds(V);
        int mst = 0;
        for(auto itr : edges){
            int wt = itr.first;
            int u = itr.second.first;
            int v = itr.second.second;

            if(ds.findParent(u)!=ds.findParent(v)){
                mst += wt;
                ds.unionByRank(u,v);
            }
        }
        return mst;
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


// } Driver Code Ends
/*
3 3
0 1 5
1 2 3
0 2 1
*/