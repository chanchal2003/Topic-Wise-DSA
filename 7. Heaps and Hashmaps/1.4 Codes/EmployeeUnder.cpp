#include<bits/stdc++.h>
using namespace std;

int getSize(unordered_map<char,unordered_set<char>> tree, char root, unordered_map<char,int> result){
    int sz = 0;
    for(char child : tree[root]){
        int childsize = getSize(tree,child,result);
        sz += childsize;
    }
    result[root] = sz;
    return sz+1;
}

void printEmployeeCountUnderEachManager(unordered_map<char,char> &mp){
    unordered_map<char,unordered_set<char>> tree;
    char root;

    for(auto relation : mp){
        char employee = relation.first;
        char manager = relation.second;
        if(manager!=employee){
            tree[manager].insert(employee);
        }
        else{
            root = manager; //if F F, so here in tree heirarchicy formed f will be at the root
        }
    }

    unordered_map<char,int> result;
    getSize(tree,root,result);

    for(auto relation : result){
        cout<<relation.first<<" "<<relation.second<<endl;
    }

}

int main(){
    int n;
    cin>>n; 
    unordered_map<char,char> mp;
    for(int i=0; i<n; i++){
        char employee,manager;
        cin>>employee>>manager;
        mp.insert({employee,manager});
    }
    printEmployeeCountUnderEachManager(mp);

    return 0;
}