/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

void backtrack(vector<vector<int>> &result,vector<int> &current,vector<int> &num,int start,int n,int k){
    if(current.size() >= k){
        result.push_back(current);
    }
    if(current.size()>=n){
        return;
    }
    for(int i=start; i<n; i++){
        current.push_back(num[i]);
        backtrack(result,current,num,i+1,n,k);
        current.pop_back();
    }
}

vector<vector<int>> subset(vector<int> &num)
{
    // Write your code here.
    vector<vector<int>> result;
    vector<int> current;
    int n=num.size();
    backtrack(result,current,num,0,n,3);
    sort(result.begin(),result.end());
    return result;
}

int main(){
    int n;
    cin>>n;
    vector<int> num;
    for(int i=0; i<n; i++){
        int element;
        cin>>element;
        num.push_back(element);
    }
    vector<vector<int>> ans = subset(num);
    for(vector<int> temp : ans){
        for(int number : temp){
            cout<<number<<" ";
        }
        cout<<endl;
    }
}