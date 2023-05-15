/*
Just remember one thing while writing this comparatorsort function, compare the elements of current array with sorted array if the element is at right position we will return true or else we will return false

RETURN THE WAY YOU WANT THE ARRAY TO LOOK LIKE
*/

#include<bits/stdc++.h>
using namespace std;

/*
bool cmp(pair<int,int> &a,pair<int,int> &b){
    if(a.first != b.first){
        if(a.first < b.first){
            return false;
        }
        return true;
    }else if(a.first == b.first){
        if(a.second < b.second){
            return true;
        }
        return false;
    } 
}
*/

bool cmp(pair<int,int> &a,pair<int,int> &b){
    if(a.second == b.second){
        return a.second < b.second;
    }
    return a.first > b.first; //return false
}

int main(){
    int n;
    cin>>n;
    vector<pair<int,int>> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i].first>>v[i].second;
    }
    cout<<endl;
    sort(v.begin(),v.end(),cmp);
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