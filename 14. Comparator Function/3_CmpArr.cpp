/*
Inbuilt comparator function says if you want to swap then return false to me, it means that it returns true when element is at its correct position 
*/

#include<bits/stdc++.h>
using namespace std;

//swap in decreasing order
/*
bool cmp(int a,int b){
    if(a > b){
        return true;
    }
    return false;
}
*/

bool cmp(int a,int b){
    if(a < b){
        return true;
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    vector<int> arr;
    for(int i=0; i<n; i++){
        int element;
        cin>>element;
        arr.push_back(element);
    }
    sort(arr.begin(),arr.end(),cmp);
    
    //this function is basically defining the behaviour of swap function
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}

/*
6
1 3 6 5 4 2
*/
