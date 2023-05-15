class DisjointSet{
    vector<int> parent,size;

    public:
    DisjointSet(int n){
        parent.resize(n+1,0);
        size.resize(n+1,0);
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

    void unionBySize(int u,int v){
        int ulp_u = findParent(u);
        int ulp_v = findParent(v);
        
        if(ulp_u == ulp_v){
            return;
        }
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_u] += size[ulp_v];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_v] += size[ulp_u];
        }
    }
};