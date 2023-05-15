#include<bits/stdc++.h>
using namespace std;

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

int main(){
    DisjointSet ds(7);
    ds.unionByRank(1, 2); 
    ds.unionByRank(2, 3); 
    ds.unionByRank(4, 5); 
    ds.unionByRank(6, 7); 
    ds.unionByRank(5, 6); 
    // if 3 and 7 same or not 
    if(ds.findParent(3) == ds.findParent(7)) {
        cout << "Same\n"; 
    }
    else cout << "Not same\n"; 

    ds.unionByRank(3, 7); 

    if(ds.findParent(3) == ds.findParent(7)) {
        cout << "Same\n"; 
    }
    else cout << "Not same\n";
    return 0;
}