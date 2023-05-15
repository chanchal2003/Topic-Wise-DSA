/*
Given a boolean 2D array, where each row is sorted. Find the row with the maximum number of 1s. 
*/

#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> v,int start,int end){
    int ans = -1;
    int m = end+1;
    while(start <= end){
        int mid = start + (end-start)/2;
        if(v[mid] == 1){
            ans = mid;
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }
    if(ans==-1){
        return 0;
    }
    return m-ans;
}

int rowWithMaxOnes(vector<vector<int>> arr,int n,int m){
    unordered_map<int,int> mp;
    vector<int> minElementArr;
    for(int i=0; i<n; i++){
        vector<int> v = arr[i];
        int minElement = binarySearch(v,0,m-1);
        mp[minElement] = i;
        minElementArr.push_back(minElement);
    }
    int maxAns = *max_element(minElementArr.begin(),minElementArr.end());
    return mp[maxAns];
}

int main(){

    int n,m;
    cout<<"Enter number of rows and columns"<<endl;
    cin>>n>>m;
    vector<vector<int>> arr;

    for(int i=0; i<n; i++){
        vector<int> temp;
        for(int j=0; j<m; j++){
            int element;
            cin>>element;
            temp.push_back(element);
        }
        arr.push_back(temp);
    }

    cout<<rowWithMaxOnes(arr,n,m)<<endl;

return 0;
}

/*
4 4
0 0 0 1
0 1 1 1
1 1 1 1
0 0 0 1
*/