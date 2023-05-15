#include<bits/stdc++.h>
using namespace std;

int binarySearchReverseSorted(vector<int> &arr,int n,int element){
    int start = 0;
    int end = n-1;
    
    while (start <= end)
    {
        int mid = start + (end-start)/2;
        if(arr[mid] == element){
            return mid;
        }    
        else if(arr[mid] < element){
            end = mid-1;
        }
        else{
            start = mid+1;
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
    
    cout<<binarySearchReverseSorted(arr,n,element)<<endl;
    return 0;
}