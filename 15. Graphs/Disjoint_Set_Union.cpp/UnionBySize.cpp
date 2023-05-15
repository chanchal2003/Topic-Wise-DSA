#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
    

    public:
    vector<int> parent,size;
    DisjointSet(int n){
        parent.resize(n+1,0);
        size.resize(n+1,0);
        for(int i=0; i<=n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int u){
        if(parent[u]==u){
            return u;
        }
        return parent[u] = findParent(parent[u]);
    }

    void unionBySize(int u,int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        if(ulp_u == ulp_v){
            return;
        }
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

int main(){
    DisjointSet ds(7);
    ds.unionBySize(1, 2); 
    ds.unionBySize(2, 3); 
    ds.unionBySize(4, 5); 
    ds.unionBySize(6, 7); 
    ds.unionBySize(5, 6); 
    // if 3 and 7 same or not 
    for(int i=1;i<=7; i++){
        cout<<ds.size[i]<<endl;
    }
    if(ds.findParent(3) == ds.findParent(7)) {
        cout << "Same\n"; 
    }
    else cout << "Not same\n"; 

    ds.unionBySize(3, 7); 

    if(ds.findParent(3) == ds.findParent(7)) {
        cout << "Same\n"; 
    }
    else cout << "Not same\n";
    return 0;
}