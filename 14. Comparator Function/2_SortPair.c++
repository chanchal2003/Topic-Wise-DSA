#include<bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a,pair<int,int> b){
    if(a.first  == b.first){
        return a.second > b.second; //if two values of a are same then the array will sorted according to ascending order
        
    }
    return a.first < b.first; //if this returns  true then the positions of a and b will be wapped and array will be sorted according to descending order 
}

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i].first>>v[i].second;
    }
    for (int i = 0; i < n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if (cmp(v[i],v[j]))
            {
                /* code */
                swap(v[i],v[j]);
            }
            
        }
    }
    
    cout<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }

    return 0;
}

/*
6
4 3
5 5
5 3
25 6
7 9
8 5
*/