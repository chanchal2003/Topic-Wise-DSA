/*
Suppose we have a sorted array and an element is placed at ith position 
in nearly sorted array that element can be placed at (i-1)th,ith and (i+1)th  position
*/

#include<bits/stdc++.h>
using namespace std;

int nearlySorted(vector<int> &arr,int n, int element){
    int start = 0;
    int end = n-1;

    while (start <= end)
    {
        int mid = start + (end-start)/2;
        if(arr[mid]==element){
            return mid;
        }
        if(mid+1>=start && arr[mid-1]==element){
            return mid-1;
        }
        if(mid+1<=end && arr[mid+1]==element){
            return mid+1;
        }
        if(arr[mid]<element){
            start = mid+2;
        }
        else{
            end = mid-2;
        }

    }
    return -1;
}

int main(){

    vector<int> arr;
    cout<<"Enter the size of the array: "<<endl;
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int element;
        cin>>element;
        arr.push_back(element);
    }
    cout<<"Enter the element to be searched"<<endl;
    int element;
    cin>>element;
    
    cout<<nearlySorted(arr,n,element)<<endl;

    return 0;
}